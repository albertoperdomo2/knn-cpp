# knn-cpp

This project is a super simple implementation of a cpp library. In this case, I decided to implement a simple algorithm such as the K-Nearest Neighbor Algorithm. With this project, rather than work on a complex project, I decided to build a simple "Machine Learning" library to perform KNN inference in order to validate some OOP concepts that I have been learnign recently as well as my knowledge on how to structure a cpp project. 

## KNN Algorithm
The k-nearest neighbor algorithm is a non-parametric (aka being distribution-free) classification that is used for both regression and classification. 

The idea behind the algorithm is really simple and it shouldn't be confused with the k-means clustering algorithm, even though some clustering might apply in this case. The KNN algorithm predicts the label of class of a data point based on the label of its K nearest neighbors, so in some sense it builds a cluster with the K nearest neightbors. The predominant class in that cluster will be given to the unknown data point, so, an object is classified by a plurarity vote of its neighbors and it's given the most common class in that neighborhood. 

It can use different types of norms to measure the distance between the neighbors, but in this case I have decided to rely on the basics and use the euclidean norm aka l2 norm. 

So, as I have stated several times, it is a simple version of the algorithm and the Knn object (which is thought to be a 'model' object) contains the following attributes and methods:

- Private methods:
	- `euclidean_distance` method, to get the l2 norm with all its neighbors. 
	- `get_knn` method, which gets the information about the k nearest neighbors based on the euclidean distance between them and the POI.

- Public methods:
	- `predict_class` method, which is the main method of the ones implemented and is the one which returns the inferred class.

- Public attributes: 
	- `neighbours_number`, which is basically `k` and defines the number of nearest neighbors to use.

The `src/main.cpp` is shows an example on how to use the 'library' (I don't think is complex/big/useful enough to be called so). It uses some data for the well-known [Iris Flower Dataset](https://en.wikipedia.org/wiki/Iris_flower_data_set). 

# TODO
There are a lot of things that I might add to this simpole project, but one of them would be build a more generalized model for the training dataset. 
