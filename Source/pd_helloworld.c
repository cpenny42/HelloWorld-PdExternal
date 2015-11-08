#include "m_pd.h"

// Pointer to our new class
static t_class *helloworld_class;

// Data for the class:
typedef struct _helloworld {
    t_object x_obj; // This is required as the first field for all objects
    
    // Any additional class variables would be declared here
    
} t_helloworld;

// Called when the object receives a "bang" message
void helloworld_bang(t_helloworld *x)
{
    post("Hi!");
}

// Called to create an instance of the class when a new object is made in Pd
// The args to this function depend on those defined with class_new() below:
//
// For A_DEFFLOAT:  t_floatarg f
// For A_DEFSYMBOL: t_symbol *s
// For A_GIMME:     t_symbol *s, int argc, t_atom *argv
//
// This class doesn't take any arguments, so none are listed here
void *helloworld_new(void)
{
    t_helloworld *x = (t_helloworld *)pd_new(helloworld_class);
   
    // If we had object variables in the struct above,
    // we would initialize them here
    
    return (void *)x;
}

void helloworld_setup(void)
{
    helloworld_class = class_new(gensym("helloworld"),         // name
                                  (t_newmethod)helloworld_new, // constructor
                                  0,                           // destructor
                                  sizeof(t_helloworld),        // struct size
                                  CLASS_DEFAULT,               // gui
                                  0);                          // arguments, ending in 0
    
    // Add a bang method for the class
    class_addbang(helloworld_class, helloworld_bang);
}
