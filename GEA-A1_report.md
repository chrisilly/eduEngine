# Lab report for Assignment 1

**Course:** DA376B - Game Engine Architecture

**Assignment title:** Entity-Component-System (ECS)
<!--**Handout:** https://docs.google.com/document/d/1qiTSHGQTvn8zbcl4l76zbZKpkx-7_tCpdbYdcHxhFXs/edit?usp=sharing-->

**Date:** 17 April 2025

**Student Name:** Chris Illy Culling

**Student ID:** an3801

## 1. Introduction

The goal of this assignment is to define and implement entity components and the systems which govern or otherwise bring their data to life at runtime. The entities themselves are created and managed using the **EnTT ECS library**[^1], a data-oriented entity component system. This is the given architecture, alongside consequential design-choices, that the formal learning objectives of this report refer to.

### 1.1 Learning Objectives

Formally, there are seven learning objectives. They are to practice the following abilities:

**Knowledge and Understanding**
1. Describe functional and non-functional properties of a given architecture.
2. Describe technologies and architectures that are present in game engines and game engine modules.

**Competence and Ability**

3. Analyse and make clear the consequences of a given design or architecture given a specific problem.
4. Design and implement game technologies according to the principles of a given design or architecture.
5. Independently be able to search and make good use of information from external sources.

**Analytical Thinking and Assessment**

6. Analyse and critically assess pros and cons of different architextures.
7. Analyse and critically assess design choices and their implementations with respect to given problems.

## 2. Implementation Appraoch

### 2.1 eduEngine Tools and Dependencies

- C++
- SDL3
- OpenGL
- assimp
- ImGui
- GLM mathematics library
- STB public domain library for C/C++
- EnTT ECS library

eduEngine as is was provided by Malmö University and was written predominantly in C++. SDL3 was used as a backend for window, sound, input, and more. OpenGL is the industry standard for high performance graphics[^2] and was used for rendering. Assimp is an asset importer used to load the 3D models in the engine. Dear Imgui is a self-proclaimed "bloat-free graphical user interface for C++ with minimal dependencies"[^3] used to render GUI elements at runtime. The GLM mathematics library was used for vector and matrix maths in the engine, and is designed for graphics software based on the OpenGL Shading Language (GLSL) specifications[^4], making it compatible with and appropriate for eduEngine. The image loader and writer of eduEngine were made using the STB library. Lastly, the assignment objective fundamentally leverages the EnTT library, which lays the foundation for a data-oriented entity component system[^1]. 

All of these tools and dependencies were selected and put-together by educators. If the tools used are not industry standards in their respective fields, they are light-weight; picked with eduEngine's educational purpose in mind, meant to be easily employed and manipulated by students who may not be previously familiar with their systems.

### 2.2 Development Environment

- Visual Studio Code: Integrated Development Environment (Editor)
- Ninja: A fast, cross-platform build system
- CMake: Build tool

Visual Studio Code was an unpopular choice of IDE amongst peers of the Game Engine Architecture course. However, it does not only easily compile and run eduEngine with the help of Ninja and CMake; it allows for greater customization of its UI, tools, etc. with the help of extensions. The primary reason for choosing Visual Studio Code over Visual Studio Community was developer familiarity; Visual Studio Code will in this circumstance make the development experience more fluid and will introduce fewer halting obstacles.

Because Visual Studio Code was opted for, Ninja and CMake were necessary for configuring and compiling the project and its C++ code.

### 2.3 Design Choices

## 3. Implementation Details

## 4. Testing and Observations

## 5. Reflection and Discussion

## 6. Conclusion

## 7. References

## 8. Appendices

[^1]: https://github.com/skypjack/entt

[^2]: https://www.opengl.org/

[^3]: https://github.com/ocornut/imgui

[^4]: https://github.com/g-truc/glm