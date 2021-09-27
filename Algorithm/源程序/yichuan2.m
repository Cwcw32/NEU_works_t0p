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
%% ����Ȧ�õ��ϺõĽ�
path=[];long=inf; 
rand('state',sum(clock));  %��ʼ�������������
tic
w=150; g=100;  %��Ⱥ��������������
rand('state',sum(clock)); 
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
       if flag==0
          J(k,c1)=1:cityNum+1;
          break 
       end
   end
end
J(:,1)=0; J=J/cityNum+1; %ת��Ϊ����
Pj=0;%ѡ�񽻲�����ĸ���
Pb=0;%ѡ���������ĸ���
min_dist=99999999;
slong=0;
%% �Ŵ��㷨
alpha=0.1;
for j=1:150  %popsize
   posibility(j)=alpha*(1-alpha).^(j-1);%ָ��
end
p=[0 cumsum(posibility)];%��������
pmax=max(p);%���ɿ̶�
for k=1:g 
        for j=1:w
        X1=[1 1+randperm(cityNum-1),cityNum+1]; 
            A(j,:)=X1; 
        end
%����
        Pj=0.7+(3*k)/g;
        for i=1:2:w
            ch1(1)=rand; %�������еĳ�ʼֵ
            gi=rand;
            if gi<(1-Pj)/2%ģ��ģ���˻�С���ʲ���
                continue;
            end
            for j=2:cityNum-1
                ch1(j)=4*ch1(j-1)*(1-ch1(j-1)); 
            end
            if i==w
                break;
            end
            ch1=2+floor(cityNum-1*ch1); 
            temp=A(i,ch1); 
            A(i,ch1)=A(i+1,ch1); 
            A(i+1,ch1)=temp;
        end
%%����
    ins=sort(ceil(cityNum*rand(1,2)));%������������� ��С��������
    I2 = ins(1);
    J2 = ins(2);
    ag=1+ceil(4*rand());
    for u=1:ag
     for i=1:w
        if rand()<0.3
         r=ceil(4*rand());
         switch r
          case 1% ��ת
            A(i,I2:J2) =fliplr(A(i,I2:J2));
          case 2 % ����
            A(i,I2:J2) = A(i,[I2+1:J2 I2]);
          case 3 % ���㽻��
            A(i,[I2 J2]) = A(i,[J2 I2]);
          otherwise 
         end
        end
     end
    end
%%ѡ��
    G=[J;A]; 
    [SG,ind1]=sort(G,2); 
    num2=size(G,1); long=zeros(1,num2); 
    for j=1:num2
        for i=1:cityNum
           long(j)=long(j)+d(ind1(j,i),ind1(j,i+1)); 
        end
    end
    [slong,ind2]=sort(long); %��·�����Ȱ��մ�С��������
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
end
%%
toc
t=toc
path=ind1(ind2(1),:);
temp=path(1);
path(1)=path(cityNum+1);
path(cityNum+1)=temp;

path
long=0;
for i=1:length(path)-1
   long=long+d(path(i),path(i+1));
end
long
path(n+1)=[];
citys(n+1,:)=[];
%citys=citys';
figure(1)
path=path;
plot([citys(path,1);citys(path(1),1)],...
    [citys(path,2);citys(path(1),2)],'-');
xlabel('������')
ylabel('������')
title(['�Ŵ��㷨�Ż�·��(��̾���:' num2str(long) ')'])
grid on
