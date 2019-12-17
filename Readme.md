<img src="liquidfun/Box2D/Documentation/Programmers-Guide/html/liquidfun-logo-square-small.png"
alt="LiquidFun logo" style="float:right;" />

LiquidFun Version [1.1.0][]

# Attempting Implementation of Turing Pattern in Movable Cellular Automaton
## B3 Mioto Takahashi
## Computational Design (Keio University)
## 71744696

Attempt in implementation of turing pattern in a particle-based fluid simulation. Testbed module is used for implementation.
I modified `turing_fluid⁩/liquidfun/Box2D⁩/Box2D⁩/Particle⁩/b2Particle.h` and `turing_fluid⁩/liquidfun/Box2D⁩/Box2D⁩/Particle⁩/b2ParticleSystem.cpp` to add a Turing Pattern functionality in `TuringColorMixing`  class and added `turing_fluid⁩/liquidfun/Box2D⁩/Testbed/TuringFluid.h` for visualization.
For building on an Xcode project in MacOS, execute the following commands.
```
cd liquidfun/Box2D
cmake -G "Xcode"
```
Build `All Build` in Xcode and run `Testbed` in order to visualize the simulation.

##### Current Problems
Slow execution. Massive drop in framerate.
