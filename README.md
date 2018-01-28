eXait Plugin for Detect Pin by TLS (Thread Local Storage) entries 
===================

Binário criado para detectar quando está sendo executado/analisado pelo PIN.


Requirements
-------------
> - Visual Studio 2010
> -  Pin funcional de acordo com a documentação [Intel] [1].

----------

What's eXait
-------------
https://www.coresecurity.com/corelabs-research/open-source-tools/exait

----------


Executing
-------------

O projeto inclui a dll já buildada.
Basta copiar o arquivo 
eXait_TLSDetectPin.dll
Para :
> eXait_v1.0\bin\plugins\

Para testar sem o Pin, basta executar no terminal:
> eXait_v1.0\bin\exait_console.exe -p eXait_TLSDetectPin.dll

> ![PIN_NOT_DETECTED](https://i.imgur.com/e89zlin.png)

Para executar com o Pin:
>pin.exe -- eXait_v1.0\bin\exait_console.exe  -p  eXait_TLSDetectPin.dll

>![PIN_DETECTED](https://i.imgur.com/kZuplhJ.png) 

----------     

Funcionamento
-------------------
O funcionamento do binário para a detecção do PIN é baseado no trabalho apresentado no Black Hat 2016 | Break Out of The Truman Show: Active Detection and Escape of Dynamic Binary Instrumentation, trabalho de Ke Sun, Xiaoning Li e Ya Ou . A apresentação está disponível neste [link](https://www.blackhat.com/docs/asia-16/materials/asia-16-Sun-Break-Out-Of-The-Truman-Show-Active-Detection-And-Escape-Of-Dynamic-Binary-Instrumentation.pdf).
ME

  [1]: https://software.intel.com/en-us/articles/pin-a-dynamic-binary-instrumentation-tool
  [2]: http://daringfireball.net/projects/markdown/syntax "Markdown"
  [3]: https://github.com/jmcmanus/pagedown-extra "Pagedown Extra"
  [4]: http://meta.math.stackexchange.com/questions/5020/mathjax-basic-tutorial-and-quick-reference
  [5]: https://code.google.com/p/google-code-prettify/
  [6]: http://highlightjs.org/
  [7]: http://bramp.github.io/js-sequence-diagrams/
  [8]: http://adrai.github.io/flowchart.js/
  [9]: https://github.com/x64dbg/x64dbg
