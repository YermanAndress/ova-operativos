package com.uceva.edu.ovaarquitectura.controller;

import jni.InfoCpu;
import org.springframework.web.bind.annotation.CrossOrigin;
import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RestController;

@RestController
@CrossOrigin
@RequestMapping("/api/lib-arquitectura")
public class JNIRestController {
    private InfoCpu infoCpu;

    public JNIRestController() {
        this.infoCpu = new InfoCpu();
    }

    @GetMapping("/cpuinfo")
    public String getInfoCpu(){
        return infoCpu.getInfoCpu();
    }
}
