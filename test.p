# Gnuplot script file for plotting data in file "force.dat"
# This file is called   test.p
set   autoscale                        # scale axes automatically
unset log                              # remove any log-scaling
unset label                            # remove any previous labels
set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Pixel intensities"
set xlabel "Time (hrs)"
set ylabel "Intensitie"
plot "observationsBackward.dat" using 1:2 title 'Red' with linespoints, "observationsLinear.dat" using 1:3 title 'Green' with linespoints, "observationsLinear.dat" using 1:4 title 'Blue'  with linespoints