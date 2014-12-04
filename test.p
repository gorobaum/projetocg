# Gnuplot script file for plotting data in file "force.dat"
# This file is called   test.p
set   autoscale                        # scale axes automatically
unset log                              # remove any log-scaling
unset label                            # remove any previous labels
set xtic auto                          # set xtics automatically
set ytic auto                          # set ytics automatically
set title "Pixel intensities"
set xlabel "Intensitie (0-255)"
set ylabel "Time (hrs)"
plot "observationsLinear.dat" using 2:1 title 'Red' with linespoints, "observationsLinear.dat" using 3:1 title 'Green' with linespoints, "observationsLinear.dat" using 4:1 title 'Blue'  with linespoints