#Loops vs apply

tam<-10000
v<-1:tam
incre<-function(a)
{return(a+1)}

start_time <- Sys.time()
nvs<-sapply(v,incre)
end_time <- Sys.time()
end_time - start_time


start_time <- Sys.time()
for (i in 1:tam)
{
  nvf<-rep(0,tam)
  nvf[i]<-v[i]+1
}
end_time <- Sys.time()
end_time - start_time

start_time <- Sys.time()
nvs<-v+1
end_time <- Sys.time()
end_time - start_time
