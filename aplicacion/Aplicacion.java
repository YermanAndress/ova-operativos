package aplicacion;
import jni.InfoCpu;
public class Aplicacion{
    InfoCpu info = null;

    static {
        System.loadLibrary("cpuinfo");
    }

    public Aplicacion(){
        this.info = new  InfoCpu();
        System.out.println(this.info.getInfoCpu());
    }

    public static void main(String[] args){
        new Aplicacion();
    }
}