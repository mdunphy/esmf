// $Id: ESMCI_XGridUtil.h,v 1.1 2011/04/26 19:48:22 feiliu Exp $
// Earth System Modeling Framework
// Copyright 2002-2011, University Corporation for Atmospheric Research, 
// Massachusetts Institute of Technology, Geophysical Fluid Dynamics 
// Laboratory, University of Michigan, National Centers for Environmental 
// Prediction, Los Alamos National Laboratory, Argonne National Laboratory, 
// NASA Goddard Space Flight Center.
// Licensed under the University of Illinois-NCSA License.

//
//-----------------------------------------------------------------------------
#ifndef ESMCI_XGridUtil_h
#define ESMCI_XGridUtil_h

#include <vector>
#include <Mesh/include/ESMCI_Mesh.h>
#include <Mesh/include/ESMCI_Sintdnode.h>
#include <Mesh/include/ESMCI_Interp.h>


namespace ESMCI {

void compute_midmesh(std::vector<sintd_node *> & sintd_nodes, std::vector<sintd_cell *> & sintd_cells, 
  int pdim, int sdim, Mesh *midmesh);
void compute_sintd_nodes_cells(int num_sintd_nodes, double * sintd_coords, int sdim, 
  std::vector<sintd_node *> * sintd_nodes, std::vector<sintd_cell *> * sintd_cells);
int online_regrid_xgrid(Mesh &srcmesh, Mesh &dstmesh, Mesh * midmesh, IWeights &wts,
  int *regridConserve, int *regridMethod,
  int *unmappedaction);

} // namespace

#endif