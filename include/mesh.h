#ifndef MFM_MESH_H
#define MFM_MESH_H

#include "element.h"
#include <algorithm>
#include <array>
#include <limits>
#include <memory>
#include <numeric>
#include <vector>

// Eigen
#include "eigen3/Eigen/Dense"

//! mfm namespace
namespace mfm {
//! Global index type for the cell
using Index = unsigned long long;

//! \brief Class that stores the information about the input mesh.
//  \brief Used for generating material points and nodes
//! \tparam Tdim Dimension
template <unsigned Tdim> class Mesh {

public:
  //! Define a vector of size dimension
  using VectorDim = Eigen::Matrix<double, Tdim, 1>;

  // Construct a mesh with a global unique id
  //! \param[in] id Global mesh id
  Mesh(const unsigned id);

  //! Constructor with mesh details included
  //! \param[in] nodal_coords - Nodal coordinates of verticies of mesh
  //! \param[in] cell_indicies - Indicies of mesh cells
  //! \param[in] etype - Element type
  //! \param[in] id Global mesh id
  Mesh(const std::vector<VectorDim> nodal_coords,
       const std::vector<std::vector<int>> cell_indices,
       const ElementTypes etype, const unsigned id);

  //! Default destructor
  ~Mesh() = default;

  //! Delete copy constructor
  Mesh(const Mesh<Tdim> &) = delete;

  //! Delete assignement operator
  Mesh &operator=(const Mesh<Tdim> &) = delete;

  //! Set element type

  //! Get element type

  //! Get mesh nodes
  // \param[out] container of mesh nodes
  std::vector<VectorDim> get_mesh_nodes() const;
  //! Get mesh cell indicies

  // Construct MATERIAL POINTS
  // Loop over each element,
  // Find quadrature points
  // Generate material points

  //! Construct quadrature points
  // void create_quadrature_points();

  //! Read velocity constraints
  // \param[out] vector container tuples of <nodeIndex,DOF,Value>
  // std::vector<std::tuple<mfm::Index,unsigned,double>>
  // read_velocity_constraints();

  //! Return id of the mesh
  unsigned id() const { return id_; }

private:
  //! Mesh id
  unsigned id_;

  //! Element type
  ElementTypes etype_;

  //! Mesh type
  std::string mesh_type_;

  //! Container of nodal coordinates
  std::vector<VectorDim> nodal_coords;

  //! Container of indicies that make up the mesh
  std::vector<std::vector<int>> cell_indicies;

  //! Element that the particular mesh is composed of
  std::shared_ptr<const Element<Tdim>> element_{nullptr};

  // Material
};

#include "mesh.tcc"

} // namespace mfm

#endif