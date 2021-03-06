#ifndef MFM_NODE_H_
#define MFM_NODE_H_

#include <array>
#include <eigen3/Eigen/Dense>
#include <limits>
#include <map>
#include <mutex>
#include <tuple>
#include <vector>

namespace mfm {

//! Global index type for the node_base
using Index = unsigned long long;

template <unsigned Tdim> class Node {
public:
  //! Define a vector of size dimension
  using VectorDim = Eigen::Matrix<double, Tdim, 1>;

  //! Constructor
  //! \param[id] id assign as the id_ of the node
  //! \param[in] coords coordinates of the node
  Node(mfm::Index id, const VectorDim &coords);

  //! Destructor
  ~Node(){};

  //! Delete copy constructor
  Node(const Node<Tdim> &) = delete;

  //! Delete assignement operator
  Node &operator=(const Node<Tdim> &) = delete;

  //! Assign coordaintes
  //! \param[in] coord Assign coord as coordinates of the nodebase
  void assign_coordinates(const VectorDim &coord) { coordinates_ = coord; }

  VectorDim coordinates() const {
    return coordinates_;
  }

private:
  //! Mutex
  std::mutex node_mutex_;

  //! nodal id
  Index id_;

  //! nodal coordinates
  VectorDim coordinates_;

  //! Degrees of freedom
  unsigned dof_{std::numeric_limits<unsigned>::max()};

  //! Mass
  double Mass;

  //! Velocity constraints
  std::map<unsigned, double> velocity_constraints_;

  //! External force

  //! Internal force

  //! Velocity

  //! Accerlation
};

#include "node.tcc"

} // namespace mfm

#endif