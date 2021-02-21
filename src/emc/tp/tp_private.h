// signatures of the - formerly exposed extern - methods of the tp
// these are used internally only now, and to populate the tp vtable
// in tpmain.c

#ifndef TP_PRIVATE_H
#define TP_PRIVATE_H

#include "posemath.h"
#include "tc_types.h"
#include "tp_types.h"
#include "tcq.h"

// for jog-while-paused:
int tpIsPaused(TP_STRUCT * tp);

int tpSnapshot(TP_STRUCT * from, TP_STRUCT * to);

#endif // TP_PRIVATE_H
