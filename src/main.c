#include <pebble.h>
/*this is an example of how variables work in C.  For now, ignore all of the set up code for the app, and we are just going to focus on a small bit of
code that focuses on how you can store information in variables.*/
  
  
  
Window *my_window;
BitmapLayer *bitmap_layer;
GBitmap *robit;

static void main_window_load(Window *window){
//Here is where we are going to work for this project---------------------------------------

//First thing is first, let's create a variable to hold the words that we want to put on the screen
// a.k.a. a "string"
 
//start playing with the code above and see if you can change the order of the pictures, and the number of times that they appear.

  
  robit = gbitmap_create_with_resource(RESOURCE_ID_ROBIT_LEFT);

  
  
  //------------------------------------------------------------------------------------------
  
  Layer *window_layer = window_get_root_layer(window);
  bitmap_layer = bitmap_layer_create(GRect(0, 0, 144, 168));

  //-------------------------------------------------------------------------------------------
  bitmap_layer_set_bitmap(bitmap_layer, robit);
  //-------------------------------------------------------------------------------------------

  layer_add_child(window_layer, bitmap_layer_get_layer(bitmap_layer));

}

static void main_window_unload(){
   bitmap_layer_destroy(bitmap_layer);
}

void handle_init(void) {
  my_window = window_create();
 
  
  window_set_window_handlers(my_window, (WindowHandlers) {
    .load = main_window_load,
    .unload = main_window_unload,
  });
  
  window_stack_push(my_window, true);
}

void handle_deinit(void) {
 window_destroy(my_window);
}


int main(void) {
  handle_init();
  app_event_loop();
  handle_deinit();
}
