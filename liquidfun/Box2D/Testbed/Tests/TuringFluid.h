//
//  TuringFluid.h
//  BlockAllocatorTests
//
//  Created by John Lime on 2019/12/11.
//

/*
* Copyright (c) 2013 Google, Inc.
*
* This software is provided 'as-is', without any express or implied
* warranty.  In no event will the authors be held liable for any damages
* arising from the use of this software.
* Permission is granted to anyone to use this software for any purpose,
* including commercial applications, and to alter it and redistribute it
* freely, subject to the following restrictions:
* 1. The origin of this software must not be misrepresented; you must not
* claim that you wrote the original software. If you use this software
* in a product, an acknowledgment in the product documentation would be
* appreciated but is not required.
* 2. Altered source versions must be plainly marked as such, and must not be
* misrepresented as being the original software.
* 3. This notice may not be removed or altered from any source distribution.
*/
#ifndef TURING_FLUID_H
#define TURING_FLUID_H

class TuringFluid : public Test
{
public:

    TuringFluid()
    {
        /* Bounding Box */
        {
            b2BodyDef bd;
            m_ground = m_world->CreateBody(&bd);
            {
                b2PolygonShape shape;
                shape.SetAsBox(0.05f, 2.0f, b2Vec2( 2.0f, 2.0f), 0.0);
                m_ground->CreateFixture(&shape, 0.0f);
            }
            {
                b2PolygonShape shape;
                shape.SetAsBox(0.05f, 2.0f, b2Vec2(-2.0f, 2.0f), 0.0);
                m_ground->CreateFixture(&shape, 0.0f);
            }
            {
                b2PolygonShape shape;
                shape.SetAsBox(2.0f, 0.05f, b2Vec2( 0.0f, 4.0f), 0.0);
                m_ground->CreateFixture(&shape, 0.0f);
            }
            {
                b2PolygonShape shape;
                shape.SetAsBox(2.0f, 0.05f, b2Vec2( 0.0f, 0.0f), 0.0);
                m_ground->CreateFixture(&shape, 0.0f);
            }
        }
        
        /* Particle System */
        // Set radius of every particle
        m_particleSystem->SetRadius(0.035f);
        // Set damping of every particle
        m_particleSystem->SetDamping(0.2f);
        
        /* Spawning Red Particle Group */
        {
            // Define particle spawn area
            b2PolygonShape shape;
            shape.SetAsBox(0.75f, 0.75f, b2Vec2(-0.75f, 2.0f), 0.0);
            
            // Define particle group
            b2ParticleGroupDef pd;
            pd.flags = b2_turingColorMixingParticle;
            pd.shape = &shape;
            pd.color.Set(255, 0, 0, 255);
            
            // Spawn particles
            m_particleSystem->CreateParticleGroup(pd);
        }
        
        /* Spawning Green Particle Group */
        {
            // Define particle spawn area
            b2PolygonShape shape;
            shape.SetAsBox(0.75f, 0.75f, b2Vec2( 0.75f, 2.0f), 0.0);
            
            // Define particle group
            b2ParticleGroupDef pd;
            pd.flags = b2_turingColorMixingParticle;
            pd.shape = &shape;
            pd.color.Set(0, 255, 0, 255);
            
            // Spawn particles
            m_particleSystem->CreateParticleGroup(pd);
        }
        
//        /* Spawning Red Particle Group */
//        {
//            // Define particle spawn area
//            b2CircleShape shape;
//            shape.m_p.Set(0.5f, 2);
//            shape.m_radius = 0.5f;
//
//            // Define particle group
//            b2ParticleGroupDef pd;
//            pd.flags = b2_turingColorMixingParticle;
//            pd.shape = &shape;
//            pd.color.Set(255, 0, 0, 255);
//
//            // Spawn particles
//            m_particleSystem->CreateParticleGroup(pd);
//        }
//
//        /* Spawning Green Particle Group */
//        {
//            // Define particle spawn area
//            b2CircleShape shape;
//            shape.m_p.Set(-0.5f, 2);
//            shape.m_radius = 0.5f;
//
//            // Define particle group
//            b2ParticleGroupDef pd;
//            pd.flags = b2_turingColorMixingParticle;
//            pd.shape = &shape;
//            pd.color.Set(0, 255, 0, 255);
//
//            // Spawn particles
//            m_particleSystem->CreateParticleGroup(pd);
//        }
    }

    float32 GetDefaultViewZoom() const
    {
        return 0.1f;
    }

    static Test* Create()
    {
        return new TuringFluid;
    }
    
protected:
    b2Body* m_ground;
};

#endif

