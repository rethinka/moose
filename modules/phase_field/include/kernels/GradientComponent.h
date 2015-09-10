/****************************************************************/
/* MOOSE - Multiphysics Object Oriented Simulation Environment  */
/*                                                              */
/*          All contents are licensed under LGPL V2.1           */
/*             See LICENSE for full restrictions                */
/****************************************************************/
#ifndef GRADIENTCOMPONENT_H
#define GRADIENTCOMPONENT_H

#include "Kernel.h"

class GradientComponent;

template<>
InputParameters validParams<GradientComponent>();

class GradientComponent : public Kernel
{
public:
  GradientComponent(const InputParameters & parameters);

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  /// Gradient of the coupled variable
  VariableGradient & _grad_v;

  /// Component of the gradient vector to match
  unsigned int _component;
};

#endif //GRADIENTCOMPONENT_H