%% ��ʼ��
clear all
clc

%% ������
[cityNum,citys] = Read('d198.tsp');

%% �����
n = size(citys,1);
citys(n+1,:)=citys(1,:);
d = zeros(n+1,n+1);

for i=1:n+1
   for j=i+1:n+1
    d(i,j)=sqrt(sum((citys(i,:) - citys(j,:)).^2));
   end
end
d=d+d';
%% ����Ȧ�õ��Ϻõĳ�ʼ��
path=[];long=inf; 
rand('state',sum(clock));  %��ʼ�������������
tic
w=150; g=100; %��Ⱥ��������������
for k=1:w  
    c=randperm(cityNum-1);
    c1=[1,c+1,cityNum+1]; 
    for t=1:cityNum+1 
        flag=0; 
    for m=1:cityNum-1
      for n=m+2:cityNum
        if d(c1(m),c1(n))+d(c1(m+1),c1(n+1))<d(c1(m),c1(m+1))+d(c1(n),c1(n+1))
           c1(m+1:n)=c1(n:-1:m+1);  flag=1; 
        end
      end
    end
%  %%
%     path1=c1;
%     for i=1:cityNum+1
%         path1(i)=randindex(path1(i));%����
%     end
%     path1, long % ���Ѳ��·����·������
%     xx=sj(path1,1);yy=sj(path1,2);
%     plot(xx,yy,'-*') %����Ѳ��·��
   if flag==0
      J(k,c1)=1:cityNum+1; break 
   end
   end
end
%% �Ŵ��㷨����
J(:,1)=0; J=J/cityNum+1; 
e=0.1^10;
alpha=0.1;
for j=1:150  %popsize
   posibility(j)=alpha*(1-alpha).^(j-1);%ָ��
end
p=[0 cumsum(posibility)];%��������
pmax=max(p);%���ɿ̶�
for k=1:g  %�ò�ѭ�������Ŵ��㷨�Ĳ��� 
    A=J; 
    c=randperm(w); 
 %����
    for i=1:2:w  
        if i==w
            break;
        end
        F=2+floor(cityNum-1*rand(1)); 
        temp=A(c(i),[F:cityNum+1]); 
        A(c(i),[F:cityNum+1])=A(c(i+1),[F:cityNum+1]); 
        A(c(i+1),F:cityNum+1)=temp;  
    end
 %����
    ins=sort(ceil(cityNum*rand(1,2)));%������������� ��С��������
    I2 = ins(1);
    J2 = ins(2);
    ag=1+ceil(4*rand());
    for u=1:ag
         for i=1:w
            A(i,I2:J2) = fliplr(A(i,I2:J2));
         end
    end
%ѡ��
    G=[J;A]; %�������Ӵ���Ⱥ����һ��
    [SG,ind1]=sort(G,2); 
    num=size(G,1); long=zeros(1,num); 
    for j=1:num
       for i=1:cityNum
           long(j)=long(j)+d(ind1(j,i),ind1(j,i+1)); 
       end
    end
    [slong,ind2]=sort(long); 
    for j=1:w
        r=pmax*rand(1);
        for m=1:w
            if(r<p(m))
                J(j,:)=G(ind2(m),:);
                break;
            end
        end
    end
    J=G(ind2(1:w),:); 
    longs(k)=slong(:,1);

end
toc
path=ind1(ind2(1),:), 
t=toc
path% ���Ѳ��·����·������
long=0;
for i=1:length(path)-1
   long=long+d(path(i),path(i+1));
end
long

citys(n+1,:)=[];
%citys=citys';
figure(1)
path=path;
plot([citys(path,1);citys(path(1),1)],...
    [citys(path,2);citys(path(1),2)],'-');
xlabel('������')
ylabel('������')
title(['ģ���˻��㷨�Ż�·��(��̾���:' num2str(long) ')'])
grid on
