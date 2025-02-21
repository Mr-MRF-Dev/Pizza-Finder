# 🍕 Pizza-Finder

![GitHub repo size](https://img.shields.io/github/repo-size/mr-mrf-dev/Pizza-Finder)
[![CMake on multiple platforms](https://github.com/Mr-MRF-Dev/Pizza-Finder/actions/workflows/cmake-multi-platform.yml/badge.svg)](https://github.com/Mr-MRF-Dev/Pizza-Finder/actions/workflows/cmake-multi-platform.yml)
[![GitHub License](https://img.shields.io/github/license/mr-mrf-dev/Pizza-Finder)](/LICENSE)

a console-based program for efficiently finding the nearest pizza shop or a specific pizza shop using [KD-Tree](https://www.baeldung.com/cs/k-d-trees).

![Screenshot](/images/screenshot.jpg)

Our project in DS (Data Structure) with C++ programming language.

## 📥 Getting Started

1. Clone the Repository

    If you have [Git](https://git-scm.com/) installed, run the following command in your terminal

    ```bash
    git clone https://github.com/Mr-MRF-Dev/Pizza-Finder.git
    ```

    Alternatively, If You Have [Github CLI](https://cli.github.com/) installed:

    ```bash
    gh repo clone Mr-MRF-Dev/Pizza-Finder
    ```

2. Navigate to the Project Directory

    ```bash
    cd ./Pizza-Finder
    ```

3. Create a build directory

    ```bash
    mkdir build
    cd build
    ```

4. Generate the Makefiles & Build the project (With [Cmake](https://cmake.org/download/))

    ```bash
    cmake ..
    make
    ```

    or use [MinGW Makefiles](https://cmake.org/cmake/help/latest/generator/MinGW%20Makefiles.html)

    ```bash
    cmake .. -G "MinGW Makefiles"
    mingw32-make
    ```

5. Run Project!

    ```bash
    .\Pizza.exe
    ```

## ⚙ Run Project in VsCode

1. Install the [CMake Tools](https://marketplace.visualstudio.com/items?itemName=ms-vscode.cmake-tools) extension from the VS Code marketplace.

2. Create a CMake Project: Open the Command Palette (`Ctrl+Shift+P`), type `CMake: Quick Start`, and follow the prompts to set up a new project. (I suggest you use the `Create From Compilers`)

3. Configure the Project: Open the Command Palette (Ctrl+Shift+P), type CMake: Configure, and select it.

4. Run and Debug: Use the Command Palette to select `CMake: Debug` to start debugging. or select `CMake: Run Without Debugging`.

## 📝 Request for Proposal ( [RFP](https://en.wikipedia.org/wiki/Request_for_proposal) )

A simple RFP for this project.

   1. `Add Area` : Add a new area.
   2. `Add Pizza Shop` : Add a new main pizza shop.
   3. `Add Branch` : Add a new branch to a pizza shop.
   4. `Delete Branch` : Remove a branch from a pizza shop.
   5. `List Pizza Shops` : List pizza shops in a neighborhood.
   6. `List Branches` : List branches of a pizza shop.
   7. `Find Nearest Pizza Shop` : Locate the nearest pizza shop.
   8. `Find Nearest Branch` : Locate the nearest branch of a pizza shop.
   9. `List Available Pizza Shops` : List pizza shops in an area.
   10. `Most Branches` : Identify the pizza shop with the most branches.
   11. `Undo Orders` : Undo selected orders.
   12. `Exit` : Quit the program

## 🤝 Contributing

we welcome any contributions you may have. If you're interested in helping out, fork the repository
and create an [Issue](https://github.com/Mr-MRF-Dev/Pizza-Finder/issues) and
[PR](https://github.com/Mr-MRF-Dev/Pizza-Finder/pulls).

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](/LICENSE) file for details.
