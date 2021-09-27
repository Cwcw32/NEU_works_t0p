%%��ʼ��
clear all
clc

% �������м�ʱ��ʼ
t0 = clock;

% ��������
[cityNum,citys]= Read('d198.tsp');

%% ������м����
n = size(citys,1);
D = zeros(n,n);
for i = 1:n
    for j = 1:n
        if i ~= j
            D(i,j) = sqrt(sum( ( citys(i,:) - citys(j,:) ).^2 ) );
        else
            D(i,j) = 1e-4;          %�趨�ĶԽǾ�������ֵ
        end
    end
end

%% ��ʼ������
m = 31;                     % ��������
vol = 0.2;                  % ��Ϣ�ػӷ�(volatilization)����
Heu_F = 1./D;               % ��������(heuristic function)
xinxisu = ones(n,n);           
Table = zeros(n,n);        
BesrPath = zeros(L,n);     
BesrLength = zeros(L,1);    
Length_ave = zeros(L,1);    
Limit_iter = 0;                    
aerfa = 1;                  
beta = 5;        
v = 1;                  
L = 100;             % ����������
%% ����Ѱ�����·��
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
            tabu = Table(i,1:(j - 1));                  % �ѷ��ʵĳ��м��ϣ����ɱ�
            allow_index = ~ismember(citys_index,tabu);  % ����˵��1������ײ���
            allow = citys_index(allow_index);           % �����ʵĳ��м���
            P = allow;
            % ������м�ת�Ƹ���
            for k = 1:length(allow)
                P(k) = xinxisu(tabu(end),allow(k))^aerfa *  Heu_F(tabu(end),allow(k))^beta;
            end
            P = P / sum(P);
            % ���̶�
            Pc = cumsum(P);             %
            target_index = find(Pc >= rand);
            target = allow(target_index(1));
            Table(i,j) = target;
        end
    end
    % ����������ϵ�·������
    Length = zeros(m,1);
    for i = 1:m
        Route = Table(i,:);
        for j = 1:(n - 1)
            Length(i) = Length(i) + D(Route(j),Route(j + 1));
        end
        Length(i) = Length(i) + D(Route(n),Route(1));
    end
    % �������·�����뼰ƽ������
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
    % ������Ϣ��
    Delta_Tau = zeros(n,n);
    % ������ϼ���
    for i = 1:m
        % ������м���
        for j = 1:(n - 1)
            Delta_Tau(Table(i,j),Table(i,j+1)) = Delta_Tau(Table(i,j),Table(i,j+1)) + 10/Length(i);
        end
        Delta_Tau(Table(i,n),Table(i,1)) = Delta_Tau(Table(i,n),Table(i,1)) + 10/Length(i);
    end
    xinxisu = (1 - vol) * xinxisu + Delta_Tau;
    % ����������1,���·����¼��
    v = v + 1;
    Table = zeros(m,n);
end

%% �����ʾ
[Shortest_Length,index] = min(BesrLength);
Shortest_Route = BesrPath(index,:);
Time_Cost = etime(clock,t0);
disp(['��̾���:' num2str(Shortest_Length)]);
disp(['���·��:' num2str( [Shortest_Route Shortest_Route(1)] )]);
disp(['������������:' num2str(Limit_iter)]);
disp(['����ִ��ʱ��:' num2str(Time_Cost),'��']);

%% ��ͼ
figure(1)
plot([ citys(Shortest_Route,1);citys(Shortest_Route(1),1) ], [ citys(Shortest_Route,2);citys(Shortest_Route(1),2) ], 'y-');
grid on;

xlabel('������');
ylabel('������');
title(['ACA���Ż�·��(��̾���:' num2str(Shortest_Length) ')']);

