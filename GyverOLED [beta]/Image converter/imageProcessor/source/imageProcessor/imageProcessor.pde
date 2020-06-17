// constants
int maxWidth = 1000;
int maxHeight = 1000;
int nodeOffset = 5;        // мин. расстояние до следующего узла
int offsetWidth = 230;     // оффсет панели управления
int maxLines = 5000;       // макс. количество линий
int lastNodeWIndow = 10;   // окно последних повторяющихся узлов
int nailLength = 2;        // "длина" одного гвоздя для расчёта

// P5
// http://www.sojamo.de/libraries/controlP5/reference/index.html
import controlP5.*;
ControlP5 cp5;
Slider2D sliderXY, sliderBC;
Slider sizeSlider;

// JAVA
import processing.serial.*;
import java.util.*;
Serial myPort;

// clipboard
import java.awt.Toolkit;
import java.awt.datatransfer.StringSelection;
import java.awt.datatransfer.Clipboard;

// image
PImage image;
PGraphics brushLayer, hiddenLayer;
int sizeX, sizeY;
int imageWidth = 100;
int imageXoffs = 0, imageYoffs = 0;
String imagePath;
int centerX;
int centerY;

// settings
float rotAngle = 0;
boolean thresholdState = false;
float thresholdValue = 0.5;
boolean grayscaleState = false;
boolean invertState = false;
int posterizeValue = 10;
boolean posterizeState = false;
float contrastValue = 1.0;
float brightnessValue = 0;
boolean ditherState = false;
boolean frameState = false;
boolean changeFlag = true;
int overlapAmount;
float subtractWidth;
int subtractAlpha;
boolean brushState = false;
int brushSize = 10;
boolean helpState = false;
color brushColor = color(255);
int brushX;
int brushY;
boolean drawBrush = false;
int imgX, imgY;
int resultWidth, resultHeight, rectX, rectY;
float rectSize;
boolean progmem = true;
int saveMode = 0;
String saveLines;
boolean langulage = false;  // 0 рус, 1 англ

void setup() {  
  size(1200, 650);
  frameRate(60);
  smooth();
  noStroke();

  imagePath = "noImage.jpg";
  image = loadImage(imagePath);
  imageWidth = image.width;

  GUIinit();
  sizeSlider.setValue(image.width);
  centerX = offsetWidth+150;
  centerY = height/2;
  rectX = (offsetWidth + width) / 2;
  rectY = height/2;
  brushLayer = createGraphics(width, height);
  hiddenLayer = createGraphics(width, height);
}

void draw() {
  if (!helpState) drawImage();    // обработка и вывод картинки
  else showHelp();  // подсказки
  drawGUI();        // выводим интерфейс
  //println(mouseX + " " + mouseY);
}

// ===============================================================

void drawGUI() {
  // панель управления
  fill(90);
  noStroke();
  rect(0, 0, offsetWidth, height);
  fill(255);
  rect(0, 225, offsetWidth, 3);
  rect(0, 440, offsetWidth, 3);
  rect(0, height-45, offsetWidth, 3);
}