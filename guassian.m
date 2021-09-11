sd = 3;
mu = 27;
x = linspace(mu-5*sd,mu+5*sd,1000);
y = 1/sqrt(2*pi*sd^2)*exp(-(x-mu).^2/(2*sd^2));
plot(x,y);
grid on
title('Guassian Curve')
xlabel('Randomly produced numbers')
ylabel('Gauss Distribution') 