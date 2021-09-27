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
%% �õ��õĳ�ʼ�⡪�����ؿ���
path=[];long=inf; %Ѳ��·�������ȳ�ʼ��
rand('state',sum(clock));  %��ʼ�������������
tic
for j=1:1000
    path0=[1 1+randperm(cityNum-1),cityNum+1]; temp=0;
    for i=1:cityNum-1
        temp=temp+d(path0(i),path0(i+1));
    end
    if temp<long
        path=path0; long=temp;
    end
end
%% ģ���˻����
e=0.1^200;%�����
L=100000;%������
ddzs=0.999;%�¶ȵ���ָ��
T=1;
for k=1:L  %�˻����
    newpath=2+floor((cityNum-1)*rand(1,2));  
    newpath=sort(newpath); c1=newpath(1);c2=newpath(2);
    df=d(path(c1-1),path(c2))+d(path(c1),path(c2+1))-d(path(c1-1),path(c1))-d(path(c2),path(c2+1));
    if df<0 %����׼��
        path=[path(1:c1-1),path(c2:-1:c1),path(c2+1:cityNum+1)]; 
        long=long+df;
    elseif exp(-df/T)>rand
        path=[path(1:c1-1),path(c2:-1:c1),path(c2+1:cityNum+1)];
        long=long+df;
    end
    T=T*ddzs;
    if T<e
        break;
    end
end
toc
t=toc
path
long=0;
for i=1:length(path)-1
    long=long+d(path(i),path(i+1));
end
long
path(n+1)=[];
citys(n+1,:)=[];
figure(1)
path=path;
plot([citys(path,1);citys(path(1),1)],...
    [citys(path,2);citys(path(1),2)],'-');
xlabel('������')
ylabel('������')
title(['ģ���˻��㷨�Ż�·��(��̾���:' num2str(long) ')'])
grid on