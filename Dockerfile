FROM openjdk:21
VOLUME /tmp
EXPOSE 8080
ARG JAR_FILE=target/Ova-Arquitectura-0.0.1-SNAPSHOT.jar
ADD ${JAR_FILE} app.jar
COPY jni/libcpuinfo.so /lib64
ENV LD_LIBRARY_PATH=/usr/local/lib/jni:/lib64:$LD_LIBRARY_PATH
ENTRYPOINT ["java","-jar","/app.jar"]