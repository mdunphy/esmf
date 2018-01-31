/**
 *  wrappers_mpi.c
 *
 *  Wrappers for MPI calls so we can trace them.
 *  These are linked statically into the executable using
 *  --wrap=SYMBOL flags to the linker.
 *
 */

#include <mpi.h>

#include "ESMCI_Macros.h"
#include "ESMCI_Trace.h"
#include "preload.h"

extern "C" {

  extern int __real_MPI_Barrier(MPI_Comm comm);
  
  int __wrap_MPI_Barrier(MPI_Comm comm) {

    // printf("__wrap_MPI_Barrier\n");
    
    if (c_esmftrace_isactive() == 1) {
      ESMCI::TraceMPIBarrierStart();
    }
    int ret = __real_MPI_Barrier(comm);
    if (c_esmftrace_isactive() == 1) {
      ESMCI::TraceMPIBarrierEnd();
    }

    return ret;
  }


  /*
  extern int __real_MPI_Ibarrier(MPI_Comm comm, MPI_Request *request);

  int __wrap_MPI_Ibarrier(MPI_Comm comm, MPI_Request *request) {
      
    if (c_esmftrace_isactive() == 1) {
      //TODO: need a custom event for this
      ESMCI::TraceEventRegionEnter("mpi_ibarrier");
    }
    int ret = __real_MPI_Ibarrier(comm, request);
    if (c_esmftrace_isactive() == 1) {
      ESMCI::TraceEventRegionExit("mpi_ibarrier");
    }
    
    return ret;
  }
  */
  
  /* MPI_Wait */
  extern int __real_MPI_Wait(MPI_Request *request, MPI_Status *status);

  int __wrap_MPI_Wait(MPI_Request *request, MPI_Status *status) {
    if (c_esmftrace_isactive() == 1) {
      ESMCI::TraceMPIWaitStart();
    }
    int ret = __real_MPI_Wait(request, status);
    if (c_esmftrace_isactive() == 1) {
      ESMCI::TraceMPIWaitEnd();
    }
    return ret;
  }

  
  
}
