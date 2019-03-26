clc
clear
close all

turnarounds = fopen('turnaround_matlab.txt');
c = textscan(turnarounds,'%d; %d'); % tutaj "%d; %d" odpowiada "ID_procesu; turnaround"
fclose(turnarounds);


ecdf(c{2})      % id nie potrzeba wiec wczytuje tylko turnaround time'y (druga kolumna c)


% ccc(1:1000,1) = c{2}(1:1000);
% ccc2=sort(ccc);
% figure()
% [f1,x1] = ecdf(ccc);
%figure()
%[f2,x2] = ecdf(ccc2);

%equalss2 = isequal(x1,x2);

%c1(1:10000,1) = c{1};
%c1(1:10000,2) = c{2};

%[f,x] = ecdf(c1(1:10000,2));
%plot(x,f)