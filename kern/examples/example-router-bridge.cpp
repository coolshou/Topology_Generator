/* -*- Mode:C++; c-file-style:"gnu"; indent-tabs-mode:nil; -*- */
/*
 * Copyright (c) 2009 Pierre Weiss <3weissp@gmail.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation;
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 * 
 */

//  Topology Generated :
//
//  PC -- BRIDGE -- PC
//          |
//        Router
//          |
//  PC -- BRIDGE -- PC
//

using namespace std;

#include <iostream>
#include <stdlib.h>
#include "../Generator.h"

int main(int argc, char *argv[])
{
  /* avoid compile warnings */
  argc = argc;
  argv = argv;
  
  Generator *gen = new Generator(std::string("example-router-bridge"));
  
  /* Add Node : */
  gen->AddNode("Pc");//0
  gen->AddNode("Pc");//1
  gen->AddNode("Bridge");//2
  
  gen->AddNode("Router");//3
  
  gen->AddNode("Bridge");//4
  gen->AddNode("Pc");//5
  gen->AddNode("Pc");//6
  
    
  /* Add the bridge. */
  gen->AddLink("Bridge", gen->listNode.at(2)->getNodeName());//link 0
  gen->listLink.at(0)->AddNodes(gen->listNode.at(0)->getNodeName());
  gen->listLink.at(0)->AddNodes(gen->listNode.at(1)->getNodeName());
  
  gen->AddLink("Bridge", gen->listNode.at(4)->getNodeName());//link 1
  gen->listLink.at(1)->AddNodes(gen->listNode.at(5)->getNodeName());
  gen->listLink.at(1)->AddNodes(gen->listNode.at(6)->getNodeName());
  
  /* link switch to router. */
  gen->listLink.at(0)->AddNodes(gen->listNode.at(3)->getNodeName());
  gen->listLink.at(1)->AddNodes(gen->listNode.at(3)->getNodeName());
  
  
  /* Add an application */
  gen->AddApplication("Ping", gen->listNode.at(0)->getNodeName(), gen->listNode.at(5)->getNodeName(), 0, 5);// 0 start time - 5 end time

  gen->GenerateCode();
  
  delete gen;
}
