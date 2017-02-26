package com.javahonk
 
class GroovyHelloWorld {
 
    def name    
    def printGroovyHelloWorld() {
        "Groovy Hello World ${name}"
    }
    
    static main(args) {
        def groovyHelloWorld = new GroovyHelloWorld()
        groovyHelloWorld.name = "Java Honk"
        println groovyHelloWorld.printGroovyHelloWorld()
        
    }
}