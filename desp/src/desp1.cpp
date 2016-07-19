#include "ros/ros.h"
#include "std_msgs/String.h"
#include "desplib.h"
#include <sstream>
#include "math.h"
#include "stdlib.h"
#include "stddef.h"
#include <sys/time.h>   //For time benchmark
#include <ctime>	//For time benchmark

typedef long long int64; typedef unsigned long long uint64; //For time benchmark

uint64 GetTimeMs64()
{

	/* Linux */
	struct timeval tv;

	gettimeofday(&tv, NULL);

	uint64 ret = tv.tv_usec;
	/* Convert from micro seconds (10^-6) to milliseconds (10^-3) */
	ret /= 1000;

	/* Adds the seconds (10^0) after converting them to milliseconds (10^-3) */
	ret += (tv.tv_sec * 1000);

	return ret;
}


using namespace faudes;

int main(int argc, char **argv)
{  // Generator g1; 
 
  ros::init(argc, argv, "desp1");

  ros::NodeHandle n;

 // ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 1000);

//  ros::Rate loop_rate(10);

  int count = 0;

  while (ros::ok())
  {


  // Primitives automata
  Generator gAuto;

  // states

  gAuto.InsState("s1");  
  gAuto.InsState("s2");                  
  gAuto.InsState("s3");
  gAuto.InsState("s4");  
  gAuto.InsState("s5");                  
  gAuto.InsState("s6");
  gAuto.InsState("s7");  
  gAuto.InsState("s8");                  
  gAuto.InsState("s9");
  gAuto.InsState("s10");  
  gAuto.InsState("s11");                  
  gAuto.InsState("s12");
  gAuto.InsState("s13");  
  gAuto.InsState("s14");                  
  gAuto.InsState("s15");
  gAuto.InsState("s16");  
  gAuto.InsState("s17");                  
  gAuto.InsState("s18");
  gAuto.InsState("s19");  
  gAuto.InsState("s20");                  
  gAuto.InsState("s21");
  gAuto.InsState("s22");  
  gAuto.InsState("s23");                  
  gAuto.InsState("s24");
  gAuto.InsState("s25");  
  gAuto.InsState("s26");                  
  gAuto.InsState("s27");
  gAuto.InsState("s28");  
  gAuto.InsState("s29");                  
  gAuto.InsState("s30");
  gAuto.InsState("s31");  
  gAuto.InsState("s32");                  
  gAuto.InsState("s33");
  gAuto.InsState("s34");  
  gAuto.InsState("s35");                  
  gAuto.InsState("s36");
  gAuto.InsState("s37");
  gAuto.InsState("s38");  
  gAuto.InsState("s39");                  
  gAuto.InsState("s40");
  gAuto.InsState("s41");

  // events
  
  Idx e1=gAuto.InsEvent("e1");   // U       
  Idx e2=gAuto.InsEvent("e2");   // UR     
  Idx e3=gAuto.InsEvent("e3");   // RU            
  Idx e4=gAuto.InsEvent("e4");   // R   
  Idx e5=gAuto.InsEvent("e5");   // RD            
  Idx e6=gAuto.InsEvent("e6");   // DR   
  Idx e7=gAuto.InsEvent("e7");   // D            
  Idx e8=gAuto.InsEvent("e8");   // DL   
  Idx e9=gAuto.InsEvent("e9");   // LD            
  Idx e10=gAuto.InsEvent("e10");  // L   
  Idx e11=gAuto.InsEvent("e11");  // LU            
  Idx e12=gAuto.InsEvent("e12");  // UL   
  Idx e13=gAuto.InsEvent("e13");  // Uw            
  Idx e14=gAuto.InsEvent("e14");  // Rw   
  Idx e15=gAuto.InsEvent("e15");  // Lw            
  Idx e16=gAuto.InsEvent("e16");  // Dw   
  Idx e17=gAuto.InsEvent("e17");  // Init
   
  // U

  gAuto.SetTransition("s1", "e1", "s2");
  gAuto.SetTransition("s2", "e13", "s1");

  // UR

  gAuto.SetTransition("s1", "e2", "s3");
  gAuto.SetTransition("s3", "e13", "s4");
  gAuto.SetTransition("s4", "e14", "s5");
  gAuto.SetTransition("s5", "e16", "s6");
  gAuto.SetTransition("s6", "e13", "s11");

  // RU

  gAuto.SetTransition("s11", "e3", "s10");
  gAuto.SetTransition("s10", "e14", "s9");
  gAuto.SetTransition("s9", "e13", "s8");
  gAuto.SetTransition("s8", "e15", "s7");
  gAuto.SetTransition("s7", "e14", "s1");

  // R

  gAuto.SetTransition("s11", "e4", "s12");
  gAuto.SetTransition("s12", "e14", "s11");

  // RD

  gAuto.SetTransition("s11", "e5", "s13");
  gAuto.SetTransition("s13", "e14", "s14");
  gAuto.SetTransition("s14", "e16", "s15");
  gAuto.SetTransition("s15", "e15", "s16");
  gAuto.SetTransition("s16", "e14", "s21");

  // DR

  gAuto.SetTransition("s21", "e6", "s20");
  gAuto.SetTransition("s20", "e16", "s19");
  gAuto.SetTransition("s19", "e14", "s18");
  gAuto.SetTransition("s18", "e13", "s17");
  gAuto.SetTransition("s17", "e16", "s11");

  // D

  gAuto.SetTransition("s21", "e7", "s22");
  gAuto.SetTransition("s22", "e16", "s21");

  // DL

  gAuto.SetTransition("s21", "e8", "s23");
  gAuto.SetTransition("s23", "e16", "s24");
  gAuto.SetTransition("s24", "e15", "s25");
  gAuto.SetTransition("s25", "e13", "s26");
  gAuto.SetTransition("s26", "e16", "s31");

  // LD

  gAuto.SetTransition("s31", "e9", "s30");
  gAuto.SetTransition("s30", "e15", "s29");
  gAuto.SetTransition("s29", "e16", "s28");
  gAuto.SetTransition("s28", "e14", "s27");
  gAuto.SetTransition("s27", "e15", "s21");

  // L

  gAuto.SetTransition("s31", "e10", "s32");
  gAuto.SetTransition("s32", "e15", "s31");

  // LU

  gAuto.SetTransition("s31", "e11", "s33");
  gAuto.SetTransition("s33", "e15", "s34");
  gAuto.SetTransition("s34", "e13", "s35");
  gAuto.SetTransition("s35", "e14", "s36");
  gAuto.SetTransition("s36", "e15", "s1");

  // UL

  gAuto.SetTransition("s1", "e12", "s40");
  gAuto.SetTransition("s40", "e13", "s39");
  gAuto.SetTransition("s39", "e15", "s38");
  gAuto.SetTransition("s38", "e16", "s37");
  gAuto.SetTransition("s37", "e13", "s31");

  // initial state
  gAuto.SetTransition("s41", "e17", "s1");
  gAuto.SetTransition("s41", "e17", "s11");
  gAuto.SetTransition("s41", "e17", "s21");
  gAuto.SetTransition("s41", "e17", "s31");

  gAuto.SetInitState("s41");              

  // marked states
  
  gAuto.SetMarkedState("s1");
  gAuto.SetMarkedState("s11");
  gAuto.SetMarkedState("s21");
  gAuto.SetMarkedState("s31");


  // inspect result on console
  std::cout << "################################\n";
  std::cout << "# tutorial, handcraft generator \n";
  gAuto.Write();
  std::cout << "################################\n";

  // png of the automata

//  gAuto.DotWrite("tmp_simplemachine.dot"); 
//  gAuto.DDotWrite("tmp_simplemachine_debug.dot");
//
//  try {
//    gAuto.GraphWrite("tmp_simplemachinie.png");
//  } catch(faudes::Exception& exception) {
//    std::cout << "1_generator: cannot execute graphviz' dot. " << std::endl;
//  } 

  





  // Map Automata
 
  Generator gMap;

  Idx i=1;
  Idx m=100;  // dimension of the map
  int k=1;
  uint64 time;

  gMap.InsEvent(e13);  // Uw            
  gMap.InsEvent(e14);  // Rw   
  gMap.InsEvent(e15);  // Lw            
  gMap.InsEvent(e16);  // Dw   


//  StateSet MapStates;



  for (i=1; i!=(m*(m+1))+1 ; ++i)
      {
        if(i<(m*m)+1)
	  {gMap.InsState(i);
	   }
	if(i>m)
	  {  
  		// Corners

	    if((i-m)==1)
	       {gMap.SetTransition(i-m, e14, i-m+1); // right
		gMap.SetTransition(i-m, e16, i);     // down
		}
	    else if((i-m)==m)
		{gMap.SetTransition(i-m, e15,i-m-1); // left
		 gMap.SetTransition(i-m, e16,i);     // down
		}
	    else if((i-m)==m*(m-1)+1)
		{gMap.SetTransition(i-m, e13, i-(2*m)); // up
		 gMap.SetTransition(i-m, e14, i-m+1);   // right
		}
	    else if((i-m)==m*m)
		{gMap.SetTransition(i-m, e15, i-m-1);   // left
		 gMap.SetTransition(i-m, e13, i-(2*m)); // up
		}
	    else if((i-m)>1 && (i-m)<m)
		{gMap.SetTransition(i-m, e15, i-m-1); // left
		 gMap.SetTransition(i-m, e14, i-m+1); // right
		 gMap.SetTransition(i-m, e16, i);     // down
		}
	    else if((i-m)>(m*(m-1)+1) && (i-m)<(m*m))
		{gMap.SetTransition(i-m, e15, i-m-1);   // left
		 gMap.SetTransition(i-m, e14, i-m+1);   // right
		 gMap.SetTransition(i-m, e13, i-(2*m)); // up
		 }		
	    else if((i-m)==(k*m)+1 && (i-m)<m*(m-1)+1)
		{gMap.SetTransition(i-m, e13, i-(2*m)); // up
		 gMap.SetTransition(i-m, e14, i-m+1); // right
		 gMap.SetTransition(i-m, e16, i);     // down
		}
	    else if((i-m)==((k+1)*m) && (i-m)<m*(m-1)+1) // Right edge
		{gMap.SetTransition(i-m, e15, i-m-1); // left
		 gMap.SetTransition(i-m, e13, i-(2*m)); // up
		 gMap.SetTransition(i-m, e16, i);     // down
		 ++k;
		}
	    else {gMap.SetTransition(i-m, e15, i-m-1); // left
		 gMap.SetTransition(i-m, e14, i-m+1); // right
		 gMap.SetTransition(i-m, e16, i);     // down
		 gMap.SetTransition(i-m, e13, i-(2*m)); // up
		  }
	   }
      }

  gMap.SetInitState(55);              

  // marked states
  
 // gMap.SetMarkedState(48);


 // gMap.Write();


  // Parallel

  Generator ParMapPrim;

  time = GetTimeMs64();

  Parallel(gAuto, gMap, ParMapPrim);

  time = GetTimeMs64() - time;
 
  ROS_INFO("Elapsed milliseconds: %llu", time);


 // ParMapPrim.Write();

 // Comp.Write();

// gMap.DotWrite("tmp_gMap.dot"); 
//  gMap.DDotWrite("tmp_gMap_debug.dot");
//
//  try {
//    gMap.GraphWrite("tmp_gMap.png");
//  } catch(faudes::Exception& exception) {
//    std::cout << "1_generator: cannot execute graphviz' dot. " << std::endl;
//  } 
  



  //  std_msgs::String msg;

 //   std::stringstream ss;
  //  ss << "hello world " << count;
 //   msg.data = ss.str();

  //  ROS_INFO("%s", msg.data.c_str());

  //  chatter_pub.publish(msg);

  // ros::spinOnce();

  //  loop_rate.sleep();
   // ++count;
  }


  return 0;
}