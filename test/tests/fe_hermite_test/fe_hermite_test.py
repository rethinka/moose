from options import *

test_hermite_3_1d = { INPUT : 'hermite-3-1d.i',
                  EXODIFF : ['hermite-3-1d_out.e'],
                  SCALE_REFINE : 5,
                  MAX_PARALLEL : 1,
                  ABS_ZERO : 1e-7
                  }

test_hermite_3_2d = { INPUT : 'hermite-3-2d.i',
                  EXODIFF : ['hermite-3-2d_out.e'],
                  SCALE_REFINE : 5,
                  MAX_PARALLEL : 1
                  }

test_hermite_3_3d = { INPUT : 'hermite-3-3d.i',
                  EXODIFF : ['hermite-3-3d_out.e'],
                  SCALE_REFINE : 5,
                  ABS_ZERO : 1e-7,
                  MAX_PARALLEL : 1
                  }

