%% 初始化
clear all
clc

%% 读数据
[cityNum,citys] = Read('d198.tsp');

%% 算距离
n = size(citys,1);
citys(n+1,:)=citys(1,:);
d = zeros(n+1,n+1);

for i=1:n+1
   for j=i+1:n+1
    d(i,j)=sqrt(sum((citys(i,:) - citys(j,:)).^2));
   end
end
d=d+d';
%% 得到好的初始解——蒙特卡洛
path=[];long1=inf; %巡航路径及长度初始化
rand('state',sum(clock));  %初始化随机数发生器
tic
for j=1:1000  %求较好的初始解
    path0=[1 1+randperm(cityNum-1),cityNum+1]; temp=0;
    for i=1:cityNum-1
        temp=temp+d(path0(i),path0(i+1));
    end
    if temp<long1
        c=path0; long1=temp;
    end
end
%% 改良圈
c(length(path0))=1;
L=cityNum;
for k=1:L
    flag=0;
    for m=1:L-2 
        for n=m+2:L
            if d(c(m),c(n))+d(c(m+1),c(n+1))<d(c(m),c(m+1))+d(c(n),c(n+1))
                c(m+1:n)=c(n:-1:m+1);
                flag=flag+1;
%                 figure(1);
%                 Shortest_Route=c;
%                 plot([citys(Shortest_Route,1);citys(Shortest_Route(1),1)],...
%                          [citys(Shortest_Route,2);citys(Shortest_Route(1),2)],'o-');
            end
        end
    end
    if flag==0
        long=0;
        for i=1:L
            long=long+d(c(i),c(i+1));
        end
        path=c;
    end
end
toc
%circle
for i=1:length(path)-1
   long=long+d(path(i),path(i+1));
end
long
%% 

%      num=size(J,1); long=zeros(1,num); %路径长度的初始值
%      for j=1:num
%         for i=1:cityNum
%             long(j)=long(j)+d(J(j,i),J(j,i+1)); %计算每条路径长度
%         end
%      end
%      [long,x]=sort(long);
%      longos=long(1)
    


figure(1)
path=path;
plot([citys(path,1);citys(path(1),1)],...
    [citys(path,2);citys(path(1),2)],'-');
xlabel('横坐标')
ylabel('纵坐标')
title(['改良圈算法优化路径(最短距离:' num2str(long) ')'])
grid on
