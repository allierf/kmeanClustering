#include <iostream>
#include <ctime>
#include <fstream>
#include <vector>
#include <sstream>
#include <unordered_map>
#include <unordered_set>

class Point {
public:
    double x,y;
    int cluster;
    double mindist;

    Point() : //default constructor to initialize the member variables
            x(0.0),
            y(0.0),
            cluster(0) {}

    Point(double x, double y) :
            x(x),
            y(y),
            cluster(0) {}


    double distance(Point p){
        return (p.x-x) * (p.x-x) + (p.y-y) * (p.y-y);
    }
};

void kMeans(std::vector<Point>& points ,int k, bool loops);
std::vector<Point> readcsv();
std::vector<Point> readtxt();

int main(){
    //std::vector<Point> points = readcsv();
    std::vector<Point> points = readtxt();
    int k = 2;
    bool loops = true;
    kMeans(points,k,loops);

    return 0;
}

void kMeans(std::vector<Point>& points, int k,bool loops) {

    std::unordered_map<int, std::vector<Point>> clusters;
    std::vector<Point> centroids;
    // randomly assigns points to the centroids
    srand(time(nullptr));
    //sets the centroidID to the key values of the unordered map and randomly selects k centroids
    for (auto i = 0; i < k; i++) {
        centroids.push_back(points.at(rand() % points.size()));
        centroids[i].cluster = i+1;
        clusters[i+1];
    }
    std::unordered_set<double> check;
    int counter = 0;
    while (loops) {
        for(int j = 0; j < points.size(); j++){
            double mindist = std::numeric_limits<double>::max();
            for(int i = 0; i < centroids.size(); i++){
                //calculate distance
                double dist = centroids[i].distance(points[j]);
                if(dist < mindist){
                    mindist = dist;
                    points[j].cluster = i+1;
                }
            }
            clusters[points[j].cluster].push_back(points[j]);
        }


        for(int i = 0; i < clusters.size(); i++){
           long double sumX = 0;
           long double sumY = 0;
            for(int j = 0; j < clusters[i].size();j++){
                sumX += clusters[i][j].x;
                sumY += clusters[i][j].y;
            }
            if(sumX != 0 && sumY !=0){
                std::cout << sumX << std::endl;
                centroids[i].x = sumX / clusters[i].size();
                if(check.count(centroids[i].x)){
                    loops = false;
                }else{
                    check.insert(centroids[i].x);
                }

                centroids[i].y = sumY / clusters[i].size();
            }

            clusters[i].clear();
        }

        counter++;
    }

    // outputting the data to the output file
    std::ofstream fout;
    std::string outputName = "output1.txt";

    fout.open(outputName,std::ios::out);
    if(!fout){
        std::cout <<"File failed to open out file" << std::endl;
        exit(1);
    }
std::cout<< "How many loops: " << counter << std::endl;
    for(auto kv : points){
        fout << kv.x << " " << kv.y << " " << kv.cluster << std::endl;
    }
    fout.close();
}

// returns a vector of points
std::vector<Point> readcsv(){
    std::vector<Point> points;
    std::string line;
    std::ifstream file("file_name");

    while(getline(file, line)) {
        std::stringstream lineStream(line);
        std::string bit;
        double x,y;
        getline(lineStream,bit,',');
        x = stof(bit);
        getline(lineStream,bit,'\n');
        y = stof(bit);

        points.push_back(Point(x,y));
    }
    return points;
}

std::vector<Point> readtxt(){
    std::vector<Point> points;
    std::ifstream fin;

    fin.open("input1.txt",std::ios::in);

    if(!fin){
        std::cout<<"File failed to open in file\n";
        exit(1);
    }
    int x,y;
    while(fin>>x){
        fin>>y;
        points.push_back(Point(x,y));
    }
    return points;
}