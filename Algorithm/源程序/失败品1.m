%% 
clear all
clc

%% 
[cityNum,citys] = Read('berlin52.tsp');

%% 
n = size(citys,1);
citys(n+1,:)=citys(1,:);
d = zeros(n+1,n+1);

for i=1:n+1
   for j=i+1:n+1
    d(i,j)=sqrt(sum((citys(i,:) - citys(j,:)).^2));
   end
end
d=d+d';
%%
path=[];long=inf; 
rand('state',sum(clock));  
%%
tic
w=150; g=100; 
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
      J(k,c1)=1:cityNum+1; break 
   end
   end
end
%%       
%     num=size(J,1); long=zeros(1,num); %路径长度的初始值
%     for j=1:num
%        for i=1:cityNum
%            long(j)=long(j)+d(J(j,i),J(j,i+1)); %计算每条路径长度
%        end
%     end
%     long=sort(long);
%     longest=long(1)
    
%%
J(:,1)=0; J=J/cityNum+1; 
e=0.1^10;
alpha=0.1;
for j=1:1000  
   posibility(j)=alpha*(1-alpha).^(j-1);%指数
end
p=[0 cumsum(posibility)];%生成轮盘
pmax=max(p);%生成刻度
for k=1:g  %该层循环进行遗传算法的操作 
    A=J; %交配产生子代A的初始染色体
    c=randperm(w); %产生下面交叉操作的染色体对 
    for i=1:2:w  
        if i==w
            break;
        end
        F=2+floor(cityNum-1*rand(1)); %产生交叉操作的地址
        temp=A(c(i),[F:cityNum+1]); %中间变量的保存值
        A(c(i),[F:cityNum+1])=A(c(i+1),[F:cityNum+1]); %交叉操作
        A(c(i+1),F:cityNum+1)=temp;  
    end
    by=[];  %为了防止下面产生空地址，这里先初始化
    while isempty(by)
        by=find(rand(1,w)<0.01); %产生变异操作的地址
    end
    B=A(by,:); %产生变异操作的初始染色体
    for j=1:length(by)
        bw=sort(2+floor(cityNum-1*rand(1,3)));  %产生变异操作的3个地址
        B(j,:)=B(j,[1:bw(1)-1,bw(2)+1:bw(3),bw(1):bw(2),bw(3)+1:cityNum+1]); %交换位置
    end
        G=[J;A;B]; %父代和子代种群合在一起
        [SG,ind1]=sort(G,2); %序列ind1
        num=size(G,1); long=zeros(1,num); %路径长度的初始值
    for j=1:num
       for i=1:cityNum
           long(j)=long(j)+d(ind1(j,i),ind1(j,i+1)); %计算每条路径长度
       end
    end
    
    long2=1./long;%适应度计算
 %%选择
    %%轮盘赌——动态
    maxlen=max(long2);
    minlen=min(long2);
    for i=1:num
        f(i)=((long2(i)+minlen)/(maxlen+minlen+1)).^k;     
    end
%    pmax=max(p);
    [slong,ind2]=sort(long2); %适应度从大到小
    for j=1:w
        r=pmax*rand(1);
        for m=1:w
            if(r<p(m))
                J(j,:)=G(ind2(m),:);
                break;
            end
        end
    end
    longs(k)=long(ind2(1));
end
toc
 path=ind1(ind2(1),:), max(longs(1))  %解的路径及路径长度
% path(n+1)=[];
% citys(n+1,:)=[];
% %citys=citys';
% figure(1)
% Shortest_Route=path;
% plot([citys(Shortest_Route,1);citys(Shortest_Route(1),1)],...
%      [citys(Shortest_Route,2);citys(Shortest_Route(1),2)],'o-');
% grid on
% xlabel('横坐标')
% ylabel('纵坐标')
% title(['模拟退火算法优化路径(最短距离:' num2str(long) ')'])
% %paint2(citys,path,L);
