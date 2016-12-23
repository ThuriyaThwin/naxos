#! /usr/bin/env gnuplot

#set termoption enhanced
#set termoption dash
set terminal epslatex color
set output "ratios_times.tex"
set size 0.66

set tics nomirror
set border 3

set key samplen 0
set pointsize 1.2

set xlabel "$d / n$"
set ylabel "$\\mathrm{TIME_{AC}} / \\mathrm{TIME_{BC}}$" offset 3

set logscale xy
set format xy "$\\scriptstyle{10^{%L}}$"

set style line 100 linetype 2 linecolor 0
set arrow from 1, 0.1 to 1, 400000 nohead linestyle 100
set arrow from 0.1, 1 to 400000, 1 nohead linestyle 100

set label "$d < n$" at 1, 100000 offset -0.3, 0.5 right
set label "$d > n$" at 1, 100000 offset +0.3, 0.5

set label "AC efficient" at 100000, 1 rotate offset 2, -0.5 right
set label "BC efficient" at 100000, 1 rotate offset 2, +0.5

plot "ACvsBC.dat" index 2 using ($7/$6):($2/$4) linestyle 2 linecolor 3 \
                  title "\\small $N$ Queens instance:", \
               "" index 3 using ($7/$6):($2/$4) linestyle 1 \
                  title "\\small Magic Square instance:", \
               "" index 4 using ($7/$6):($2/$4) linestyle 3 linecolor 4 \
                  title "\\small Crew Scheduling instance:"

set output
