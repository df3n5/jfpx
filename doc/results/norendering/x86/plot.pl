set terminal png transparent nocrop enhanced font arial 8 size 420,320 
set output 'histograms.1.png'
set datafile missing '-'
set style data linespoints
set xtics border in scale 1,0.5 nomirror rotate by -45  offset character 0, 0, 0 
set xtics   ("1891-1900" 0.00000, "1901-1910" 1.00000, "1911-1920" 2.00000, "1921-1930" 3.00000, "1931-1940" 4.00000, "1941-1950" 5.00000, "1951-1960" 6.00000, "1961-1970" 7.00000)
set title "US immigration from Europe by decade" 
plot 'immigration.dat' using 2:xtic(1) t 2, '' u 3 t 3, '' u 4 t 4, '' u 5 t 5, '' u 6 t 6, '' u 7 t 7, '' u 8 t 8, '' u 9 t 9, '' u 10 t 10, '' u 11 t 11, '' u 12 t 12, '' u 13 t 13, '' u 14 t 14, '' u 15 t 15, '' u 16 t 16, '' u 17 t 17, '' u 18 t 18, '' u 19 t 19, '' u 20 t 20, '' u 21 t 21, '' u 22 t 22
#
