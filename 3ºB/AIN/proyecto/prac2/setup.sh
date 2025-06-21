pkill -9 -f pygomas

pygomas manager -np 20 -j manager_yjpellam@gtirouter.dsic.upv.es -sj service_yjpellam@gtirouter.dsic.upv.es &
sleep 4
pygomas render &
pygomas run -g pygomas.json

