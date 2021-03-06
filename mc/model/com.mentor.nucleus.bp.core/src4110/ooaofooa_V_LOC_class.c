/*----------------------------------------------------------------------------
 * File:  ooaofooa_V_LOC_class.c
 *
 * Class:       Variable Location  (V_LOC)
 * Component:   ooaofooa
 *
 * your copyright statement can go here (from te_copyright.body)
 *--------------------------------------------------------------------------*/

#include "sys_sys_types.h"
#include "LOG_bridge.h"
#include "POP_bridge.h"
#include "T_bridge.h"
#include "ooaofooa_classes.h"

/*
 * Instance Loader (from string data).
 */
Escher_iHandle_t
ooaofooa_V_LOC_instanceloader( Escher_iHandle_t instance, const c_t * avlstring[] )
{
  Escher_iHandle_t return_identifier = 0;
  ooaofooa_V_LOC * self = (ooaofooa_V_LOC *) instance;
  /* Initialize application analysis class attributes.  */
  self->Id = (Escher_iHandle_t) Escher_atoi( avlstring[ 1 ] );
  return_identifier = self->Id;
  self->LineNumber = Escher_atoi( avlstring[ 2 ] );
  self->StartPosition = Escher_atoi( avlstring[ 3 ] );
  self->EndPosition = Escher_atoi( avlstring[ 4 ] );
  self->Var_ID = (Escher_iHandle_t) Escher_atoi( avlstring[ 5 ] );
  return return_identifier;
}

/*
 * Select any where using referential/identifying attribute set.
 * If not_empty, relate this instance to the selected instance.
 */
void ooaofooa_V_LOC_batch_relate( Escher_iHandle_t instance )
{
  ooaofooa_V_LOC * ooaofooa_V_LOC_instance = (ooaofooa_V_LOC *) instance;
  ooaofooa_V_VAR * ooaofooa_V_VARrelated_instance1 = (ooaofooa_V_VAR *) Escher_instance_cache[ (intptr_t) ooaofooa_V_LOC_instance->Var_ID ];
  if ( ooaofooa_V_VARrelated_instance1 ) {
    ooaofooa_V_LOC_R835_Link( ooaofooa_V_VARrelated_instance1, ooaofooa_V_LOC_instance );
  }
}


/*
 * RELATE V_VAR TO V_LOC ACROSS R835
 */
void
ooaofooa_V_LOC_R835_Link( ooaofooa_V_VAR * part, ooaofooa_V_LOC * form )
{
  /* Use TagEmptyHandleDetectionOn() to detect empty handle references.  */
  form->Var_ID = part->Var_ID;
  form->V_VAR_R835 = part;
  Escher_SetInsertElement( &part->V_LOC_R835, (Escher_ObjectSet_s *) form );
}

/*
 * UNRELATE V_VAR FROM V_LOC ACROSS R835
 */
void
ooaofooa_V_LOC_R835_Unlink( ooaofooa_V_VAR * part, ooaofooa_V_LOC * form )
{
  /* Use TagEmptyHandleDetectionOn() to detect empty handle references.  */
  form->Var_ID = 0;
  form->V_VAR_R835 = 0;
  Escher_SetRemoveElement( &part->V_LOC_R835, (Escher_ObjectSet_s *) form );
}

/*
 * Dump instances in SQL format.
 */
void
ooaofooa_V_LOC_instancedumper( Escher_iHandle_t instance )
{
  ooaofooa_V_LOC * self = (ooaofooa_V_LOC *) instance;
  printf( "INSERT INTO V_LOC VALUES ( %ld,%d,%d,%d,%ld );\n",
    ((long)self->Id & ESCHER_IDDUMP_MASK),
    self->LineNumber,
    self->StartPosition,
    self->EndPosition,
    ((long)self->Var_ID & ESCHER_IDDUMP_MASK) );
}
/*
 * Statically allocate space for the instance population for this class.
 * Allocate space for the class instance and its attribute values.
 * Depending upon the collection scheme, allocate containoids (collection
 * nodes) for gathering instances into free and active extents.
 */
static Escher_SetElement_s ooaofooa_V_LOC_container[ ooaofooa_V_LOC_MAX_EXTENT_SIZE ];
static ooaofooa_V_LOC ooaofooa_V_LOC_instances[ ooaofooa_V_LOC_MAX_EXTENT_SIZE ];
Escher_Extent_t pG_ooaofooa_V_LOC_extent = {
  {0,0}, {0,0}, &ooaofooa_V_LOC_container[ 0 ],
  (Escher_iHandle_t) &ooaofooa_V_LOC_instances,
  sizeof( ooaofooa_V_LOC ), 0, ooaofooa_V_LOC_MAX_EXTENT_SIZE
  };


