
head(attenu)

#************* Media *************#

#mean(attenu$event) #date irelevante
#mean(attenu$station) #date irelevante
mean(attenu$mag)
mean(attenu$dist)
mean(attenu$accel)



#************* Varianta *************#

var(attenu)



#************* Plot *************#

par(mfrow=c(1, 3))
#scatter.smooth(attenu$event) #date irelevante
#scatter.smooth(attenu$station) #date irelevante
scatter.smooth(attenu$mag)
scatter.smooth(attenu$dist)
scatter.smooth(attenu$accel)



#************* Quartile *************#

par(mfrow=c(1, 3))
#boxplot(attenu$event) #date irelevante
#boxplot(attenu$station) #date irelevante
boxplot(attenu$mag)
boxplot(attenu$dist)
boxplot(attenu$accel)



#************* Regresie simpla *************#

RegS <- lm(dist ~ accel, data=attenu)#calculez regresia  
abline(RegS)#reprezentare grafica
plot(RegS)
print(RegS)#afisez informatii
summary(RegS)#afisez informatii  
AIC(RegS)
BIC(RegS)



#************* Regresie multipla *************#

RegM <- lm(event ~ mag + dist + accel, data=attenu) #calculez regresia
abline(RegM)#reprezentare grafica
plot(RegM)
print(RegM)#afisez informatii
summary(RegM)#afisez informatii  
AIC(RegM)
BIC(RegM)



#************* Distributia Rayleigh *************#
# pentru functia drayleigh am folosit pachetul VGAM
# pentru functia densityPlot am folosit pachetul car

a = max(attenu$dist)
par(mfrow=c(1,2))
plot(attenu$dist, drayleigh(attenu$dist, a))#functia de repartitie 
densityPlot(drayleigh(attenu$event, a))#functia densitate de probabilitate




