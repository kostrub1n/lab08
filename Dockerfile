FROM ubuntu:20.04

RUN apt-get update && apt-get install -y \
    cmake \
    g++ \
    make

WORKDIR /usr/src/app

COPY . .

RUN mkdir build

RUN cd build && cmake .. && make

CMD ["./build/logger"]
