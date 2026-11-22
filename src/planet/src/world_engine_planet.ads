with Interfaces.C;

package World_Engine_Planet is
   function Planet_Test return Interfaces.C.double
     with
       Export        => True,
       Convention    => C,
       External_Name => "world_engine_planet_test_impl";
end World_Engine_Planet;