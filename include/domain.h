#ifndef MFM_DOMAIN_H_
#define MFM_DOMAIN_H_

#include "node.h"
#include <eigen3/Eigen/Dense>
#include <memory>
#include <vector>

namespace mfm {

//! Domain class
//! \brief Class that stores information about the domain
//! \details domain class which stores the particles, nodes, cells.
//! \tparam Tdim Dimension
template <unsigned Tdim> class Domain {

public:
  //! Define a vector of size dimension
  using VectorDim = Eigen::Matrix<double, Tdim, 1>;

  // Construct a mesh with a global unique id
  //! \param[in] id Global mesh id
  Domain(unsigned id);

  //! Default destructor
  ~Domain() = default;

  //! Delete copy constructor
  Domain(const Domain<Tdim> &) = delete;

  //! Delete assignement operator
  Domain &operator=(const Domain<Tdim> &) = delete;

  //! Return id of domain
  unsigned id() const { return id_; }

  //! Create nodes from coordinates
  //! \param[in] gnid Global node id
  //! \param[in] coordinates Nodal coordinates
  //! \param[in] check_duplicates Parameter to check duplicates
  //! \retval status Create node status
  bool create_nodes(mfm::Index gnid, const std::vector<VectorDim> &coordinates,
                    bool check_duplicates = true);

  //! Add a node to the domain
  //! \param[in] node A shared pointer to node
  //! \param[in] check_duplicates Parameter to check duplicates
  //! \retval insertion_status Return the successful addition of a node
  bool add_node(const std::shared_ptr<mfm::Node<Tdim>> &node,
                bool check_duplicates = true);

  //! Remove a node from the domain
  //! \param[in] node A shared pointer to node
  //! \retval insertion_status Return the successful addition of a node
  bool remove_node(const std::shared_ptr<mfm::Node<Tdim>> &node);

  //! Number of nodes in the domain
  mfm::Index nnodes() const { return nodes_.size(); }

  //! Assign velocity constraints to nodes
  //! \param[in] velocity_constraints Constraint at node, dir, and velocity
  bool assign_velocity_constraints(
      const std::vector<std::tuple<mfm::Index, unsigned, double>>
          &velocity_constraints);

  //! Generate points
  //! \param[in] nquadratures Number of points per direction in cell
  //! \retval point Material point coordinates
  void generate_material_points(unsigned nquadratures = 1);

  //! Return Nodal coordinates
  std::vector<VectorDim> nodal_coordinates() const;

private:
  unsigned id_;

  //! Container of material points

  //! Container of nodes
  std::vector<std::shared_ptr<Node<Tdim>>> nodes_;

  //! Mesh object
  // Initial mesh of the problem

  //! Map of nodes for fast retrieval

  //! Container of cells

  //! Container of active cells

  //! Logger
};

#include "domain.tcc"

} // namespace mfm

#endif