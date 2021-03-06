//* This file is part of the MOOSE framework
//* https://www.mooseframework.org
//*
//* All rights reserved, see COPYRIGHT for full restrictions
//* https://github.com/idaholab/moose/blob/master/COPYRIGHT
//*
//* Licensed under LGPL 2.1, please see LICENSE for details
//* https://www.gnu.org/licenses/lgpl-2.1.html

#ifndef COMPUTE2DFINITESTRAIN_H
#define COMPUTE2DFINITESTRAIN_H

#include "ComputeFiniteStrain.h"

class Compute2DFiniteStrain;

template <>
InputParameters validParams<Compute2DFiniteStrain>();

/**
 * Compute2DFiniteStrain defines a strain increment and a rotation increment
 * for finite strains in 2D geometries, handling the out of plane strains.
 * Compute2DFiniteStrain contains a virtual method to define the out-of-plane strain
 * as a general nonzero value in the inherited classes ComputePlaneFiniteStrain
 * and ComputeAxisymmetricRZFiniteStrain.
 */
class Compute2DFiniteStrain : public ComputeFiniteStrain
{
public:
  Compute2DFiniteStrain(const InputParameters & parameters);

protected:
  void initialSetup() override;
  virtual void displacementIntegrityCheck() override;
  virtual void computeProperties() override;

  /// Computes the current out-of-plane component of the displacement gradient; as a virtual function, this function is
  /// overwritten for the specific geometries defined by inheriting classes
  virtual Real computeOutOfPlaneGradDisp() = 0;

  /// Computes the old out-of-plane component of the displacement gradient; as a virtual function, this function is
  /// overwritten for the specific geometries defined by inheriting classes
  virtual Real computeOutOfPlaneGradDispOld() = 0;

  const unsigned int _out_of_plane_direction;
};

#endif // COMPUTE2DFINITESTRAIN_H
