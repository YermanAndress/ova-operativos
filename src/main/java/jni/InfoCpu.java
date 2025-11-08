package jni;

public class InfoCpu {
    public native String getInfoCpu();

    public InfoCpu(){
        try {
            System.loadLibrary("cpuinfo");
            System.out.println("Biblioteca cargada exitosamente!");
        } catch (UnsatisfiedLinkError e) {
            System.err.println("Carga de la biblioteca fallida: " + e.getMessage());
        }
    }
}