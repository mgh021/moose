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

#ifndef TIMEDERIVATIVE_H
#define TIMEDERIVATIVE_H

#include "TimeKernel.h"

// Forward Declaration
class TimeDerivative;

template<>
InputParameters validParams<TimeDerivative>();

class TimeDerivative : public TimeKernel
{
public:
  TimeDerivative(const InputParameters & parameters);
  TimeDerivative(const std::string & deprecated_name, InputParameters parameters); // DEPRECATED CONSTRUCTOR

  virtual void computeJacobian();

protected:
  virtual Real computeQpResidual();
  virtual Real computeQpJacobian();

  bool _lumping;
};

#endif //TIMEDERIVATIVE_H
