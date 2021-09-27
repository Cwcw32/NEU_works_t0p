%%初始化
clear all
clc

% 程序运行计时开始
t0 = clock;

% 导入数据
[cityNum,citys]= Read('d198.tsp');

%% 计算城市间距离
n = size(citys,1);
D = zeros(n,n);
for i = 1:n
    for j = 1:n
        if i ~= j
            D(i,j) = sqrt(sum( ( citys(i,:) - citys(j,:) ).^2 ) );
        else
            D(i,j) = 1e-4;          %设定的对角矩阵修正值
        end
    end
end

%% 初始化参数
m = 31;                     % 蚂蚁数量
vol = 0.2;                  % 信息素挥发(volatilization)因子
Heu_F = 1./D;               % 启发函数(heuristic function)
xinxisu = ones(n,n);           
Table = zeros(n,n);        
BesrPath = zeros(L,n);     
BesrLength = zeros(L,1);    
Length_ave = zeros(L,1);    
Limit_iter = 0;                    
aerfa = 1;                  
beta = 5;        
v = 1;                  
L = 100;             % 最大迭代次数
%% 迭代寻找最佳路径
while v <= L
    start = zeros(m,1);
    for i = 1:m
        temp = randperm(n);
        start = temp(1);
    end
    Table(:,1) = start;
    citys_index = 1:n;
    for i =1:m
        for j = 2:n
            tabu = Table(i,1:(j - 1));                  % 已访问的城市集合（禁忌表）
            allow_index = ~ismember(citys_index,tabu);  % 参数说明1（程序底部）
            allow = citys_index(allow_index);           % 待访问的城市集合
            P = allow;
            % 计算城市间转移概率
            for k = 1:length(allow)
                P(k) = xinxisu(tabu(end),allow(k))^aerfa *  Heu_F(tabu(end),allow(k))^beta;
            end
            P = P / sum(P);
            % 轮盘赌
            Pc = cumsum(P);             %
            target_index = find(Pc >= rand);
            target = allow(target_index(1));
            Table(i,j) = target;
        end
    end
    % 计算各个蚂蚁的路径距离
    Length = zeros(m,1);
    for i = 1:m
        Route = Table(i,:);
        for j = 1:(n - 1)
            Length(i) = Length(i) + D(Route(j),Route(j + 1));
        end
        Length(i) = Length(i) + D(Route(n),Route(1));
    end
    % 计算最短路径距离及平均距离
    if v == 1
        [min_Length, min_index] = min(Length);
        BesrLength(v) = min_Length;
        Length_ave(v) = mean(Length);
        BesrPath(v,:) = Table(min_index,:);
        Limit_iter = 1;
    else
        [min_Length,min_index] = min(Length);
        BesrLength(v) = min(BesrLength(v - 1),min_Length);
        Length_ave(v) = mean(Length);
        if BesrLength(v) == min_Length
            BesrPath(v,:) = Table(min_index,:);
            Limit_iter = v;
        else
            BesrPath(v,:) = BesrPath((v - 1),:);
        end
    end
    % 更新信息素
    Delta_Tau = zeros(n,n);
    % 逐个蚂蚁计算
    for i = 1:m
        % 逐个城市计算
        for j = 1:(n - 1)
            Delta_Tau(Table(i,j),Table(i,j+1)) = Delta_Tau(Table(i,j),Table(i,j+1)) + 10/Length(i);
        end
        Delta_Tau(Table(i,n),Table(i,1)) = Delta_Tau(Table(i,n),Table(i,1)) + 10/Length(i);
    end
    xinxisu = (1 - vol) * xinxisu + Delta_Tau;
    % 迭代次数加1,清空路径记录表
    v = v + 1;
    Table = zeros(m,n);
end

%% 结果显示
[Shortest_Length,index] = min(BesrLength);
Shortest_Route = BesrPath(index,:);
Time_Cost = etime(clock,t0);
disp(['最短距离:' num2str(Shortest_Length)]);
disp(['最短路径:' num2str( [Shortest_Route Shortest_Route(1)] )]);
disp(['收敛迭代次数:' num2str(Limit_iter)]);
disp(['程序执行时间:' num2str(Time_Cost),'秒']);

%% 绘图
figure(1)
plot([ citys(Shortest_Route,1);citys(Shortest_Route(1),1) ], [ citys(Shortest_Route,2);citys(Shortest_Route(1),2) ], 'y-');
grid on;

xlabel('横坐标');
ylabel('纵坐标');
title(['ACA最优化路径(最短距离:' num2str(Shortest_Length) ')']);

