function [n_citys,city_position] = Read(filename)
fid = fopen(filename,'rt');
location=[];
A = [1 2];
tline = fgetl(fid);
while ischar(tline)
if(strcmp(tline,'NODE_COORD_SECTION'))
while ~isempty(A)
A=fscanf(fid,'%f',[3,1]);
if isempty(A)
break;
end
location=[location;A(2:3)'];
end
end
tline = fgetl(fid); 
if strcmp(tline,'EOF')
break;
end
end
[m,n]=size(location);
n_citys = m;
city_position=location;
fclose(fid);
end