# kmeanClustering

The K-mean clustering algorithm runs until convergence. The k cluster size must be set in the main function.
I created "k-meansVisual.py" to visualize the data in a python script.
The program requires that the input file and output file is already created

To run the "kmeansClustering.cpp" :
g++ -o kmeans kmeansClustering.cpp
./kmeans

If you want to change the .txt files then you have to change the names in the .cpp file.
fin.open("input4.txt",std::ios::in);
fout.open("output4.txt",std::ios::out);

To use the python visualizer:
you have change the name of the output file
pd.read_table("output2.txt",..
