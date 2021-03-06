/****************************************************************/
/*               DO NOT MODIFY THIS HEADER                      */
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*           (c) 2010 Battelle Energy Alliance, LLC             */
/*                   ALL RIGHTS RESERVED                        */
/*                                                              */
/*          Prepared by Battelle Energy Alliance, LLC           */
/*            Under Contract No. DE-AC07-05ID14517              */
/*            With the U. S. Department of Energy               */
/*                                                              */
/*            See COPYRIGHT for full restrictions               */
/****************************************************************/

// MOOSE includes
#include "NearestNodeDistanceAux.h"
#include "NearestNodeLocator.h"
#include "MooseMesh.h"

template<>
InputParameters validParams<NearestNodeDistanceAux>()
{
  InputParameters params = validParams<AuxKernel>();
  params.addRequiredParam<BoundaryName>("paired_boundary", "The boundary to find the distance to.");
  params.set<bool>("use_displaced_mesh") = true;
  return params;
}

NearestNodeDistanceAux::NearestNodeDistanceAux(const InputParameters & parameters) :
    AuxKernel(parameters),
    _nearest_node(_nodal ? getNearestNodeLocator(parameters.get<BoundaryName>("paired_boundary"), boundaryNames()[0]) : getQuadratureNearestNodeLocator(parameters.get<BoundaryName>("paired_boundary"), boundaryNames()[0]))
{
  if (boundaryNames().size() > 1)
    mooseError("NearestNodeDistanceAux can only be used with one boundary at a time!");
}

Real
NearestNodeDistanceAux::computeValue()
{
  if (_nodal)
    return _nearest_node.distance(_current_node->id());

  Node * qnode = _mesh.getQuadratureNode(_current_elem, _current_side, _qp);

  return _nearest_node.distance(qnode->id());
}
