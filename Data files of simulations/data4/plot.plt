set term jpeg
set pm3d map
do for [i=0:69501]{
if(i%500 ==0){
out_file = sprintf('/home/kapil/IISC/data4/plots/img%04d.jpeg',i/1000)
set output out_file
splot 'data'.i.'.dat'
}
} 

