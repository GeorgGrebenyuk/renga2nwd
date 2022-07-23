# renga_3d-export
[In progress now!] Plugin to convert renga's model to 3D-data formats (now - for Autodesk Navisworks - NWC and FBX)

## External dependencies (Внешние зависимости):
1. Renga SDK (all header's file (in "Renga_imprort.h") and RengaCOMAPI.tlb). Download SDK [here](https://rengabim.com/sdk/);
2. Autodesk Navisworks SDK, nwcreate-lib; download SDK [here](https://www.autodesk.com/developer-network/platform-technologies/navisworks). I am using 2022 version;
3. Autodesk FBX SDK (2019.5);

## About using (Об использовании):
Приложение работает по принципу плагина в Renga. Вызывается по нажатии на кнопку "3D" на главной панели задач.

![Вид плагина](https://github.com/GeorgGrebenyuk/renga_3d-export/blob/main/docs/screen_1.png)

У плагина есть настраиваемые параметры:

- "Учитывать скрытые объекты": объекты, скрытые Пользователем в модели не попадут в экспортируемый файл. Опция не работает при выборе режима экспорта "Сетки с материалами";

- "не учитывать объекты с числом полигонов более" (и форма ввода максимального числа полигонов): опция для ограничения представления геометрии высокополигональных объектов. Если опция выделена и введено разумное число  максимального числа полигонов ```> 0``` -- опция будт учитываться;

- "Пересчитывать координаты": применять пересчет координат отталкиваясь от параметров, указанных в Свойствах проекта. Подробнее [читай в Справке](https://help.rengabim.com/ru/index.htm#ifc.htm). Если свойства названы/настроены неверно, то пересчет не учиытвается. 

- режим экспорта объектов: при выборе первой опции станут недоступны опции для учета скрытых объектов и учета свойств объектов; опция "сетки с материалами" больше рекомендуется для экспорта в графические форматы;
- 
## О поддержке объектов
- экспорт идет только объектов из 3D-представления, для которых есть методы получения геометрии;
- в сборках нет возможности сопоставить объект сборки со стилем или свойствами, поэтому перед экспортом рекомендуется взрывать все сборки;
- пока не реализована поддержка расчетных свойств и параметрических свойств;

## О поддерживаемых форматах экспорта
- Autodesk NWC;
- Autodesk FBX, binary;

## Планы на будущее
- Autodesk(?) FBX, \*.fbx;
- SketchUp, \*.skp;
- GMSH, \*.msh;
- CityGML, \*.gml;
- Rhino, \*.3dm;
- Chronos group GLTF, \*.gltf/\*.glb;
