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
                shape.SetAsBox(0.05f, 2.0f, b2Vec2( 2.0f, 0.0f), 0.0);
                m_ground->CreateFixture(&shape, 5.0f);
            }
            {
                b2PolygonShape shape;
                shape.SetAsBox(0.05f, 2.0f, b2Vec2(-2.0f, 0.0f), 0.0);
                m_ground->CreateFixture(&shape, 5.0f);
            }
            {
                b2PolygonShape shape;
                shape.SetAsBox(2.0f, 0.05f, b2Vec2(0.0f, 2.0f), 0.0);
                m_ground->CreateFixture(&shape, 5.0f);
            }
            {
                b2PolygonShape shape;
                shape.SetAsBox(2.0f, 0.05f, b2Vec2(0.0f, -2.0f), 0.0);
                m_ground->CreateFixture(&shape, 5.0f);
            }
        }
        
        /* Particle System */
        // Set radius of every particle
        m_particleSystem->SetRadius(0.025f);
        // Set damping of every particle
        m_particleSystem->SetDamping(0.2f);

        /* Spawning Particle Group */
        {
            // Define particle group
            b2ParticleGroupDef pd;
            pd.flags = b2_turingColorMixingParticle;

            // Define particle spawn area
            b2PolygonShape shape;
            shape.SetAsBox(2.0f, 2.0f, b2Vec2(0.0f, 0.0f), 0.0);
            pd.shape = &shape;

            // Spawn particles
            b2ParticleGroup * const group = m_particleSystem->CreateParticleGroup(pd);
            if (pd.flags & (b2_colorMixingParticle | b2_turingColorMixingParticle))
            {
                ColorParticleGroup(group, 0);
            }
        }
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

