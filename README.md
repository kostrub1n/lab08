#LAB8
# Dockerfile
```
FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    make

WORKDIR /usr/src/app

COPY . .

RUN mkdir build

RUN cd build && cmake .. && make

CMD ["./build/message_writer"]
```

# CMakeLists.txt
```
cmake_minimum_required(VERSION 3.15)

project(logger)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(message_writer logger.cpp)
```
# actions.yml
```
name: Build

on: [push]

jobs:
  build:
    runs-on: ubuntu-latest

    steps:
    - name: Checkout repository
      uses: actions/checkout@v2

    - name: Build Docker image
      run: docker build -t message-writer .

    - name: Run Docker container
      run: docker run --name message-writer-container message-writer

    - name: Copy output file
      run: docker cp message-writer-container:/usr/src/app/output.txt ./output.txt

    - name: Display output file
      run: cat ./output.txt
```
