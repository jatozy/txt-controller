FROM ubuntu:19.04
RUN apt-get update && apt-get install wget xz-utils -y
RUN cd /opt && \
    wget https://releases.linaro.org/components/toolchain/binaries/7.2-2017.11/arm-linux-gnueabihf/gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabihf.tar.xz && \
    tar -xf gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabihf.tar.xz && \
    rm -f gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabihf.tar.xz
RUN cd /opt && \
    wget https://releases.linaro.org/components/toolchain/binaries/7.2-2017.11/arm-linux-gnueabihf/sysroot-glibc-linaro-2.25-2017.11-arm-linux-gnueabihf.tar.xz && \
    tar -xf sysroot-glibc-linaro-2.25-2017.11-arm-linux-gnueabihf.tar.xz && \
    rm -f sysroot-glibc-linaro-2.25-2017.11-arm-linux-gnueabihf.tar.xz
    
FROM ubuntu:19.04
RUN apt-get update && apt-get upgrade -y && apt-get install cmake git clang-format -y
RUN mkdir /workspace
COPY --from=0 /opt/gcc-linaro-7.2.1-2017.11-x86_64_arm-linux-gnueabihf/ /opt/compiler/
COPY --from=0 /opt/sysroot-glibc-linaro-2.25-2017.11-arm-linux-gnueabihf/ /opt/sysroot/
