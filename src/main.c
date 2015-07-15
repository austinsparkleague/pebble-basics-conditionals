#include <pebble.h>
/*this is an example of how variables work in C.  For now, ignore all of the set up code for the app, and we are just going to focus on a small bit of
code that focuses on how you can store information in variables.*/
    
Window *my_window;
BitmapLayer *bitmap_layer;
GBitmap *robit;

static void main_window_load(Window *window){
//Here is where we are going to work for this project---------------------------------------

  //CONDITIONALS:
  //conditionals are a big deal in programming, they are the decision makers.
  //Meaning they allow us to run a block of code, or not run it depending on some condition.
  
  //let's do one with pictures now:
  //don't worry too much about how we are diplaying the image, we can get into that later, for now let's just focus on the
  //machinery that either displays robit the robot facing left, facing right, or whistling.
  
  //first off let's create an arbitrary value to test.  In our apps we'll usually be using a variable that represents some action,
  //like whether or not a button has been pressed, or how much time has passed, etc.  but to start off with let's just use an integer.
  int test_value = 3;
  
  
  
  //IF STATEMENTS:  The if statment is a simple but very powerful tool to change the flow of your code.
  if(test_value > 1){
  robit = gbitmap_create_with_resource(RESOURCE_ID_ROBIT_LEFT);
  }
  
  //ELSE: the if statement can be written without an "else", but when you add this at the end of an if statment
  //you gain the ability to handle many different conditions, not just the one specified above
  else{
  robit = gbitmap_create_with_resource(RESOURCE_ID_ROBIT_RIGHT);
  }
  
//********************************************************************************************************  
  //SWITCH:  
  //The following statement explicitly states what you would like to happen with each value.
  //if when you run this code, you get a blank screen, make sure you have updated the "test_value" above
  // to a value that has a case in the switch statement.

   // "Comment out"" the if/else stuff above and uncomment this code below to see the switch in action
  // note: the fastest way to comment out a bunch of stuff at once is to highlight it and press "ctrl + /"
  
//   switch (test_value) {
//  case 1:
//     robit = gbitmap_create_with_resource(RESOURCE_ID_ROBIT_LEFT);
//     break;
//  case 2:
//     robit = gbitmap_create_with_resource(RESOURCE_ID_ROBIT_LEFT);
//     break;
//  case 3:
//    robit = gbitmap_create_with_resource(RESOURCE_ID_ROBIT_WHISTLE);
//     break;
//  }
  
  
  //------------------------------------------------------------------------------------------
  
  Layer *window_layer = window_get_root_layer(window);
  bitmap_layer = bitmap_layer_create(GRect(0, 0, 144, 168));

  bitmap_layer_set_bitmap(bitmap_layer, robit);
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
