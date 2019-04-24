#ifndef MFM_MESH_H
#define MFM_MESH_H


#include <algorithm>
#include <array>
#include <limits>
#include <memory>
#include <numeric>
#include <vector>
#include "element.h"

// Eigen 
#include "eigen3/Eigen/Dense"



namespace mfm
{

//! Global index type for the cell
using Index = unsigned long long;

template <unsigned Tdim>
class Mesh
{

public:


	//! Define a vector of size dimension
	using VectorDim = Eigen::Matrix<double, Tdim, 1>;

	// Construct a mesh with a global unique id
 	//! \param[in] id Global mesh id
  	Mesh(unsigned id);

 	//! Default destructor
 	~Mesh() = default;

  	//! Delete copy constructor
  	Mesh(const Mesh<Tdim>&) = delete;

  	//! Delete assignement operator
 	Mesh& operator=(const Mesh<Tdim>&) = delete;

 	//! Construct mesh from given input indicies
 	//! \param[in] mesh indicies
 	//! \param[in] element type
 	void create_mesh(std::vector<std::vector<int>> indicies);

  	//! Return id of the mesh
	unsigned id() const { return id_; }


private:

	//! Mesh id 
	mfm::Index id_;

	//! Mesh type
	std::string mesh_type_;

	//! Container of elements
	std::vector<Element<Tdim>> elements_;






};










}







#endif