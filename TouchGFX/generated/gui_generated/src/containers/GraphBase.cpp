/*********************************************************************************/
/********** THIS FILE IS GENERATED BY TOUCHGFX DESIGNER, DO NOT MODIFY ***********/
/*********************************************************************************/
#include <gui_generated/containers/GraphBase.hpp>
#include <touchgfx/Color.hpp>
#include <texts/TextKeysAndLanguages.hpp>

GraphBase::GraphBase()
{
    setWidth(155);
    setHeight(190);
    dynamicGraph1.setScale(1);
    dynamicGraph1.setPosition(0, 15, 145, 174);
    dynamicGraph1.setGraphAreaMargin(10, 25, 0, 15);
    dynamicGraph1.setGraphAreaPadding(0, 5, 0, 2);
    dynamicGraph1.setGraphRangeY(-50, 200);

    dynamicGraph1MinorYAxisGrid.setScale(1);
    dynamicGraph1MinorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(148, 148, 148));
    dynamicGraph1MinorYAxisGrid.setInterval(10);
    dynamicGraph1MinorYAxisGrid.setLineWidth(1);
    dynamicGraph1MinorYAxisGrid.setMajorGrid(dynamicGraph1MajorYAxisGrid);
    dynamicGraph1.addGraphElement(dynamicGraph1MinorYAxisGrid);

    dynamicGraph1MajorXAxisGrid.setScale(1);
    dynamicGraph1MajorXAxisGrid.setColor(touchgfx::Color::getColorFromRGB(79, 79, 79));
    dynamicGraph1MajorXAxisGrid.setInterval(180);
    dynamicGraph1MajorXAxisGrid.setLineWidth(2);
    dynamicGraph1.addGraphElement(dynamicGraph1MajorXAxisGrid);

    dynamicGraph1MajorYAxisGrid.setScale(1);
    dynamicGraph1MajorYAxisGrid.setColor(touchgfx::Color::getColorFromRGB(117, 117, 117));
    dynamicGraph1MajorYAxisGrid.setInterval(50);
    dynamicGraph1MajorYAxisGrid.setLineWidth(2);
    dynamicGraph1.addGraphElement(dynamicGraph1MajorYAxisGrid);

    dynamicGraph1MajorYAxisLabel.setScale(1);
    dynamicGraph1MajorYAxisLabel.setInterval(50);
    dynamicGraph1MajorYAxisLabel.setLabelTypedText(touchgfx::TypedText(T___SINGLEUSE_HNSD));
    dynamicGraph1MajorYAxisLabel.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    dynamicGraph1.addLeftElement(dynamicGraph1MajorYAxisLabel);

    dynamicGraph1Line1Painter.setColor(touchgfx::Color::getColorFromRGB(97, 177, 81));
    dynamicGraph1Line1.setPainter(dynamicGraph1Line1Painter);
    dynamicGraph1Line1.setLineWidth(2);
    dynamicGraph1.addGraphElement(dynamicGraph1Line1);

    dynamicGraph1.addDataPoint(53.30818f);
    dynamicGraph1.addDataPoint(59.33081f);
    dynamicGraph1.addDataPoint(65.10852f);
    dynamicGraph1.addDataPoint(70.60102f);
    dynamicGraph1.addDataPoint(75.77097f);
    dynamicGraph1.addDataPoint(80.5843f);
    dynamicGraph1.addDataPoint(85.01048f);
    dynamicGraph1.addDataPoint(89.02274f);
    dynamicGraph1.addDataPoint(92.59832f);
    dynamicGraph1.addDataPoint(95.71863f);
    dynamicGraph1.addDataPoint(98.36941f);
    dynamicGraph1.addDataPoint(100.54081f);
    dynamicGraph1.addDataPoint(102.22747f);
    dynamicGraph1.addDataPoint(103.42857f);
    dynamicGraph1.addDataPoint(104.14775f);
    dynamicGraph1.addDataPoint(104.39316f);
    dynamicGraph1.addDataPoint(104.17727f);
    dynamicGraph1.addDataPoint(103.51683f);
    dynamicGraph1.addDataPoint(102.43263f);
    dynamicGraph1.addDataPoint(100.94935f);
    dynamicGraph1.addDataPoint(99.09532f);
    dynamicGraph1.addDataPoint(96.90225f);
    dynamicGraph1.addDataPoint(94.40493f);
    dynamicGraph1.addDataPoint(91.64091f);
    dynamicGraph1.addDataPoint(88.65019f);
    dynamicGraph1.addDataPoint(85.47479f);
    dynamicGraph1.addDataPoint(82.15842f);
    dynamicGraph1.addDataPoint(78.74609f);
    dynamicGraph1.addDataPoint(75.28366f);
    dynamicGraph1.addDataPoint(71.81743f);
    dynamicGraph1.addDataPoint(68.39376f);
    dynamicGraph1.addDataPoint(65.05862f);
    dynamicGraph1.addDataPoint(61.85716f);
    dynamicGraph1.addDataPoint(58.83334f);
    dynamicGraph1.addDataPoint(56.02949f);
    dynamicGraph1.addDataPoint(53.48595f);
    dynamicGraph1.addDataPoint(51.24072f);
    dynamicGraph1.addDataPoint(49.32904f);
    dynamicGraph1.addDataPoint(47.78316f);
    dynamicGraph1.addDataPoint(46.63196f);
    dynamicGraph1.addDataPoint(45.90075f);
    dynamicGraph1.addDataPoint(45.61098f);
    dynamicGraph1.addDataPoint(45.78005f);
    dynamicGraph1.addDataPoint(46.42115f);
    dynamicGraph1.addDataPoint(47.54314f);
    dynamicGraph1.addDataPoint(49.1504f);
    dynamicGraph1.addDataPoint(51.24285f);
    dynamicGraph1.addDataPoint(53.81585f);
    dynamicGraph1.addDataPoint(56.86031f);
    dynamicGraph1.addDataPoint(60.36266f);
    dynamicGraph1.addDataPoint(64.30502f);
    dynamicGraph1.addDataPoint(68.66529f);
    dynamicGraph1.addDataPoint(73.41735f);
    dynamicGraph1.addDataPoint(78.53128f);
    dynamicGraph1.addDataPoint(83.97354f);
    dynamicGraph1.addDataPoint(89.70733f);
    dynamicGraph1.addDataPoint(95.69281f);
    dynamicGraph1.addDataPoint(101.88749f);
    dynamicGraph1.addDataPoint(108.24655f);
    dynamicGraph1.addDataPoint(114.72321f);
    dynamicGraph1.addDataPoint(121.26915f);
    dynamicGraph1.addDataPoint(127.83488f);
    dynamicGraph1.addDataPoint(134.37018f);
    dynamicGraph1.addDataPoint(140.8245f);
    dynamicGraph1.addDataPoint(147.14741f);
    dynamicGraph1.addDataPoint(153.289f);
    dynamicGraph1.addDataPoint(159.20032f);
    dynamicGraph1.addDataPoint(164.83379f);
    dynamicGraph1.addDataPoint(170.1436f);
    dynamicGraph1.addDataPoint(175.08611f);
    dynamicGraph1.addDataPoint(179.62019f);
    dynamicGraph1.addDataPoint(183.70762f);
    dynamicGraph1.addDataPoint(187.31338f);
    dynamicGraph1.addDataPoint(190.40594f);
    dynamicGraph1.addDataPoint(192.95759f);
    dynamicGraph1.addDataPoint(194.9446f);
    dynamicGraph1.addDataPoint(196.3475f);
    dynamicGraph1.addDataPoint(197.15118f);
    dynamicGraph1.addDataPoint(197.3451f);
    dynamicGraph1.addDataPoint(196.92332f);
    dynamicGraph1.addDataPoint(195.88458f);
    dynamicGraph1.addDataPoint(194.23233f);
    dynamicGraph1.addDataPoint(191.97468f);
    dynamicGraph1.addDataPoint(189.12439f);
    dynamicGraph1.addDataPoint(185.69871f);
    dynamicGraph1.addDataPoint(181.71925f);
    dynamicGraph1.addDataPoint(177.21187f);
    dynamicGraph1.addDataPoint(172.20639f);
    dynamicGraph1.addDataPoint(166.73638f);
    dynamicGraph1.addDataPoint(160.8389f);
    dynamicGraph1.addDataPoint(154.55417f);
    dynamicGraph1.addDataPoint(147.92526f);
    dynamicGraph1.addDataPoint(140.9977f);
    dynamicGraph1.addDataPoint(133.81917f);
    dynamicGraph1.addDataPoint(126.43904f);
    dynamicGraph1.addDataPoint(118.908f);
    dynamicGraph1.addDataPoint(111.27764f);
    dynamicGraph1.addDataPoint(103.60002f);
    dynamicGraph1.addDataPoint(95.92723f);
    dynamicGraph1.addDataPoint(88.311f);
    dynamicGraph1.addDataPoint(80.80223f);
    dynamicGraph1.addDataPoint(73.45062f);
    dynamicGraph1.addDataPoint(66.3042f);
    dynamicGraph1.addDataPoint(59.40903f);
    dynamicGraph1.addDataPoint(52.80873f);
    dynamicGraph1.addDataPoint(46.54419f);
    dynamicGraph1.addDataPoint(40.65324f);
    dynamicGraph1.addDataPoint(35.17031f);
    dynamicGraph1.addDataPoint(30.12617f);
    dynamicGraph1.addDataPoint(25.54773f);
    dynamicGraph1.addDataPoint(21.45778f);
    dynamicGraph1.addDataPoint(17.87482f);
    dynamicGraph1.addDataPoint(14.81297f);
    dynamicGraph1.addDataPoint(12.28182f);
    dynamicGraph1.addDataPoint(10.28641f);
    dynamicGraph1.addDataPoint(8.82718f);
    dynamicGraph1.addDataPoint(7.90001f);
    dynamicGraph1.addDataPoint(7.49625f);
    dynamicGraph1.addDataPoint(7.60286f);
    dynamicGraph1.addDataPoint(8.20252f);
    dynamicGraph1.addDataPoint(9.27377f);
    dynamicGraph1.addDataPoint(10.7913f);
    dynamicGraph1.addDataPoint(12.72608f);
    dynamicGraph1.addDataPoint(15.04574f);
    dynamicGraph1.addDataPoint(17.71478f);
    dynamicGraph1.addDataPoint(20.69494f);
    dynamicGraph1.addDataPoint(23.94555f);
    dynamicGraph1.addDataPoint(27.42388f);
    dynamicGraph1.addDataPoint(31.08555f);
    dynamicGraph1.addDataPoint(34.88491f);
    dynamicGraph1.addDataPoint(38.77545f);
    dynamicGraph1.addDataPoint(42.71023f);
    dynamicGraph1.addDataPoint(46.6423f);
    dynamicGraph1.addDataPoint(50.52511f);
    dynamicGraph1.addDataPoint(54.31294f);
    dynamicGraph1.addDataPoint(57.9613f);
    dynamicGraph1.addDataPoint(61.42733f);
    dynamicGraph1.addDataPoint(64.67017f);
    dynamicGraph1.addDataPoint(67.65136f);
    dynamicGraph1.addDataPoint(70.33513f);
    dynamicGraph1.addDataPoint(72.68879f);
    dynamicGraph1.addDataPoint(74.68296f);
    dynamicGraph1.addDataPoint(76.29187f);
    dynamicGraph1.addDataPoint(77.49357f);
    dynamicGraph1.addDataPoint(78.27017f);
    dynamicGraph1.addDataPoint(78.60794f);
    dynamicGraph1.addDataPoint(78.49751f);
    dynamicGraph1.addDataPoint(77.93389f);
    dynamicGraph1.addDataPoint(76.91656f);
    dynamicGraph1.addDataPoint(75.4495f);
    dynamicGraph1.addDataPoint(73.5411f);
    dynamicGraph1.addDataPoint(71.20417f);
    dynamicGraph1.addDataPoint(68.45576f);
    dynamicGraph1.addDataPoint(65.31707f);
    dynamicGraph1.addDataPoint(61.81326f);
    dynamicGraph1.addDataPoint(57.97323f);
    dynamicGraph1.addDataPoint(53.82938f);
    dynamicGraph1.addDataPoint(49.41731f);
    dynamicGraph1.addDataPoint(44.77556f);
    dynamicGraph1.addDataPoint(39.94524f);
    dynamicGraph1.addDataPoint(34.9697f);
    dynamicGraph1.addDataPoint(29.89412f);
    dynamicGraph1.addDataPoint(24.76518f);
    dynamicGraph1.addDataPoint(19.63059f);
    dynamicGraph1.addDataPoint(14.53873f);
    dynamicGraph1.addDataPoint(9.53818f);
    dynamicGraph1.addDataPoint(4.67735f);
    dynamicGraph1.addDataPoint(0.00401f);
    dynamicGraph1.addDataPoint(-4.43509f);
    dynamicGraph1.addDataPoint(-8.59466f);
    dynamicGraph1.addDataPoint(-12.43125f);
    dynamicGraph1.addDataPoint(-15.90365f);
    dynamicGraph1.addDataPoint(-18.97321f);
    dynamicGraph1.addDataPoint(-21.60424f);
    dynamicGraph1.addDataPoint(-23.76431f);
    dynamicGraph1.addDataPoint(-25.42452f);
    dynamicGraph1.addDataPoint(-26.55979f);
    dynamicGraph1.addDataPoint(-27.14906f);
    dynamicGraph1.addDataPoint(-27.17553f);
    dynamicGraph1.addDataPoint(-26.62675f);
    dynamicGraph1.addDataPoint(-25.49484f);
    dynamicGraph1.addDataPoint(-23.77648f);
    dynamicGraph1.addDataPoint(-21.47302f);
    dynamicGraph1.addDataPoint(-18.59046f);
    dynamicGraph1.addDataPoint(-15.13941f);
    dynamicGraph1.addDataPoint(-11.13504f);
    dynamicGraph1.addDataPoint(-6.59697f);
    dynamicGraph1.addDataPoint(-1.5491f);
    dynamicGraph1.addDataPoint(3.98057f);
    dynamicGraph1.addDataPoint(9.96013f);
    dynamicGraph1.addDataPoint(16.35405f);
    dynamicGraph1.addDataPoint(23.12344f);
    dynamicGraph1.addDataPoint(30.22636f);
    dynamicGraph1.addDataPoint(37.61818f);
    dynamicGraph1.addDataPoint(45.25191f);
    dynamicGraph1.addDataPoint(53.07861f);
    dynamicGraph1.addDataPoint(61.04776f);
    dynamicGraph1.addDataPoint(69.10769f);
    dynamicGraph1.addDataPoint(77.20597f);
    dynamicGraph1.addDataPoint(85.28989f);
    dynamicGraph1.addDataPoint(93.30684f);
    dynamicGraph1.addDataPoint(101.20475f);
    dynamicGraph1.addDataPoint(108.93254f);
    dynamicGraph1.addDataPoint(116.44048f);
    dynamicGraph1.addDataPoint(123.68065f);
    dynamicGraph1.addDataPoint(130.6073f);
    dynamicGraph1.addDataPoint(137.17722f);
    dynamicGraph1.addDataPoint(143.35009f);
    dynamicGraph1.addDataPoint(149.08882f);
    dynamicGraph1.addDataPoint(154.35981f);
    dynamicGraph1.addDataPoint(159.13326f);
    dynamicGraph1.addDataPoint(163.38337f);
    dynamicGraph1.addDataPoint(167.08855f);
    dynamicGraph1.addDataPoint(170.23159f);
    dynamicGraph1.addDataPoint(172.7998f);
    dynamicGraph1.addDataPoint(174.78506f);
    dynamicGraph1.addDataPoint(176.1839f);
    dynamicGraph1.addDataPoint(176.99753f);
    dynamicGraph1.addDataPoint(177.23176f);
    dynamicGraph1.addDataPoint(176.89696f);
    dynamicGraph1.addDataPoint(176.00798f);
    dynamicGraph1.addDataPoint(174.58395f);
    dynamicGraph1.addDataPoint(172.64816f);
    dynamicGraph1.addDataPoint(170.22778f);
    dynamicGraph1.addDataPoint(167.35368f);
    dynamicGraph1.addDataPoint(164.06012f);
    dynamicGraph1.addDataPoint(160.38442f);
    dynamicGraph1.addDataPoint(156.36667f);
    dynamicGraph1.addDataPoint(152.04935f);
    dynamicGraph1.addDataPoint(147.47696f);
    dynamicGraph1.addDataPoint(142.69565f);
    dynamicGraph1.addDataPoint(137.75275f);
    dynamicGraph1.addDataPoint(132.69645f);
    dynamicGraph1.addDataPoint(127.57529f);
    dynamicGraph1.addDataPoint(122.43781f);
    dynamicGraph1.addDataPoint(117.33208f);
    dynamicGraph1.addDataPoint(112.30528f);
    dynamicGraph1.addDataPoint(107.40333f);
    dynamicGraph1.addDataPoint(102.67046f);
    dynamicGraph1.addDataPoint(98.14886f);
    dynamicGraph1.addDataPoint(93.87826f);
    dynamicGraph1.addDataPoint(89.89565f);
    dynamicGraph1.addDataPoint(86.23493f);
    dynamicGraph1.addDataPoint(82.92662f);
    dynamicGraph1.addDataPoint(79.9976f);
    dynamicGraph1.addDataPoint(77.47092f);
    dynamicGraph1.addDataPoint(75.36552f);
    dynamicGraph1.addDataPoint(73.69617f);
    dynamicGraph1.addDataPoint(72.47327f);
    dynamicGraph1.addDataPoint(71.70283f);
    dynamicGraph1.addDataPoint(71.38637f);
    dynamicGraph1.addDataPoint(71.52093f);
    dynamicGraph1.addDataPoint(72.09913f);
    dynamicGraph1.addDataPoint(73.10921f);
    dynamicGraph1.addDataPoint(74.53517f);
    dynamicGraph1.addDataPoint(76.35686f);
    dynamicGraph1.addDataPoint(78.55024f);
    dynamicGraph1.addDataPoint(81.08754f);
    dynamicGraph1.addDataPoint(83.93754f);
    dynamicGraph1.addDataPoint(87.06584f);
    dynamicGraph1.addDataPoint(90.43516f);
    dynamicGraph1.addDataPoint(94.00569f);
    dynamicGraph1.addDataPoint(97.73543f);
    dynamicGraph1.addDataPoint(101.5806f);
    dynamicGraph1.addDataPoint(105.49597f);
    dynamicGraph1.addDataPoint(109.43533f);
    dynamicGraph1.addDataPoint(113.35184f);
    dynamicGraph1.addDataPoint(117.19853f);
    dynamicGraph1.addDataPoint(120.92862f);
    dynamicGraph1.addDataPoint(124.49603f);
    dynamicGraph1.addDataPoint(127.85576f);
    dynamicGraph1.addDataPoint(130.96426f);
    dynamicGraph1.addDataPoint(133.77988f);
    dynamicGraph1.addDataPoint(136.26321f);
    dynamicGraph1.addDataPoint(138.37748f);
    dynamicGraph1.addDataPoint(140.08883f);
    dynamicGraph1.addDataPoint(141.36668f);
    dynamicGraph1.addDataPoint(142.184f);
    dynamicGraph1.addDataPoint(142.51754f);
    dynamicGraph1.addDataPoint(142.34809f);
    dynamicGraph1.addDataPoint(141.66061f);
    dynamicGraph1.addDataPoint(140.44446f);
    dynamicGraph1.addDataPoint(138.69345f);
    dynamicGraph1.addDataPoint(136.40592f);
    dynamicGraph1.addDataPoint(133.58484f);
    dynamicGraph1.addDataPoint(130.23771f);
    dynamicGraph1.addDataPoint(126.37661f);
    dynamicGraph1.addDataPoint(122.01805f);
    dynamicGraph1.addDataPoint(117.1829f);
    dynamicGraph1.addDataPoint(111.89621f);
    dynamicGraph1.addDataPoint(106.18701f);
    dynamicGraph1.addDataPoint(100.08811f);
    dynamicGraph1.addDataPoint(93.63582f);
    dynamicGraph1.addDataPoint(86.86968f);
    dynamicGraph1.addDataPoint(79.8321f);
    dynamicGraph1.addDataPoint(72.56809f);
    dynamicGraph1.addDataPoint(65.12481f);
    dynamicGraph1.addDataPoint(57.55127f);
    dynamicGraph1.addDataPoint(49.89787f);
    dynamicGraph1.addDataPoint(42.216f);
    dynamicGraph1.addDataPoint(34.55765f);
    dynamicGraph1.addDataPoint(26.97494f);
    dynamicGraph1.addDataPoint(19.51974f);
    dynamicGraph1.addDataPoint(12.24319f);
    dynamicGraph1.addDataPoint(5.19531f);
    dynamicGraph1.addDataPoint(-1.57538f);
    dynamicGraph1.addDataPoint(-8.02235f);
    dynamicGraph1.addDataPoint(-14.10135f);
    dynamicGraph1.addDataPoint(-19.77082f);
    dynamicGraph1.addDataPoint(-24.99222f);
    dynamicGraph1.addDataPoint(-29.73037f);
    dynamicGraph1.addDataPoint(-33.95369f);
    dynamicGraph1.addDataPoint(-37.6345f);
    dynamicGraph1.addDataPoint(-40.74923f);
    dynamicGraph1.addDataPoint(-43.27862f);
    dynamicGraph1.addDataPoint(-45.20785f);
    dynamicGraph1.addDataPoint(-46.52669f);
    dynamicGraph1.addDataPoint(-47.22956f);
    dynamicGraph1.addDataPoint(-47.31557f);
    dynamicGraph1.addDataPoint(-46.78854f);
    dynamicGraph1.addDataPoint(-45.65692f);
    dynamicGraph1.addDataPoint(-43.93375f);
    dynamicGraph1.addDataPoint(-41.63655f);
    dynamicGraph1.addDataPoint(-38.78712f);
    dynamicGraph1.addDataPoint(-35.41138f);
    dynamicGraph1.addDataPoint(-31.53917f);
    dynamicGraph1.addDataPoint(-27.20393f);
    dynamicGraph1.addDataPoint(-22.44249f);
    dynamicGraph1.addDataPoint(-17.29467f);
    dynamicGraph1.addDataPoint(-11.80304f);
    dynamicGraph1.addDataPoint(-6.01245f);
    dynamicGraph1.addDataPoint(0.03028f);
    dynamicGraph1.addDataPoint(6.27675f);
    dynamicGraph1.addDataPoint(12.67746f);
    dynamicGraph1.addDataPoint(19.18216f);
    dynamicGraph1.addDataPoint(25.74029f);
    dynamicGraph1.addDataPoint(32.30143f);
    dynamicGraph1.addDataPoint(38.81571f);
    dynamicGraph1.addDataPoint(45.23423f);
    dynamicGraph1.addDataPoint(51.50945f);
    dynamicGraph1.addDataPoint(57.59562f);
    dynamicGraph1.addDataPoint(63.44913f);
    dynamicGraph1.addDataPoint(69.02891f);
    dynamicGraph1.addDataPoint(74.29672f);
    dynamicGraph1.addDataPoint(79.21751f);
    dynamicGraph1.addDataPoint(83.75968f);
    dynamicGraph1.addDataPoint(87.89534f);
    dynamicGraph1.addDataPoint(91.60054f);
    dynamicGraph1.addDataPoint(94.85546f);
    dynamicGraph1.addDataPoint(97.64456f);
    dynamicGraph1.addDataPoint(99.9567f);
    dynamicGraph1.addDataPoint(101.7852f);
    dynamicGraph1.addDataPoint(103.1279f);
    dynamicGraph1.addDataPoint(103.98716f);
    dynamicGraph1.addDataPoint(104.36982f);
    dynamicGraph1.addDataPoint(104.28709f);
    dynamicGraph1.addDataPoint(103.75449f);
    dynamicGraph1.addDataPoint(102.79164f);
    dynamicGraph1.addDataPoint(101.42213f);
    dynamicGraph1.addDataPoint(99.67323f);
    dynamicGraph1.addDataPoint(97.5757f);
    dynamicGraph1.addDataPoint(95.16345f);
    dynamicGraph1.addDataPoint(92.47328f);
    dynamicGraph1.addDataPoint(89.5445f);
    dynamicGraph1.addDataPoint(86.41857f);
    dynamicGraph1.addDataPoint(83.13877f);
    dynamicGraph1.addDataPoint(79.74975f);
    dynamicGraph1.addDataPoint(76.29717f);
    dynamicGraph1.addDataPoint(72.82725f);
    dynamicGraph1.addDataPoint(69.38638f);
    dynamicGraph1.addDataPoint(66.02068f);
    dynamicGraph1.addDataPoint(62.77558f);
    dynamicGraph1.addDataPoint(59.69542f);
    dynamicGraph1.addDataPoint(56.82307f);
    dynamicGraph1.addDataPoint(54.19949f);
    dynamicGraph1.addDataPoint(51.86337f);
    dynamicGraph1.addDataPoint(49.85082f);
    dynamicGraph1.addDataPoint(48.19499f);
    dynamicGraph1.addDataPoint(46.92576f);
    dynamicGraph1.addDataPoint(46.06952f);
    dynamicGraph1.addDataPoint(45.64886f);
    dynamicGraph1.addDataPoint(45.68239f);
    dynamicGraph1.addDataPoint(46.18455f);
    dynamicGraph1.addDataPoint(47.16546f);
    dynamicGraph1.addDataPoint(48.63083f);
    dynamicGraph1.addDataPoint(50.58187f);
    dynamicGraph1.addDataPoint(53.01529f);
    dynamicGraph1.addDataPoint(55.92329f);
    dynamicGraph1.addDataPoint(59.29359f);
    dynamicGraph1.addDataPoint(63.10956f);
    dynamicGraph1.addDataPoint(67.35032f);
    dynamicGraph1.addDataPoint(71.99091f);
    dynamicGraph1.addDataPoint(77.00248f);
    dynamicGraph1.addDataPoint(82.35253f);
    dynamicGraph1.addDataPoint(88.00518f);
    dynamicGraph1.addDataPoint(93.92145f);
    dynamicGraph1.addDataPoint(100.05957f);
    dynamicGraph1.addDataPoint(106.37539f);
    dynamicGraph1.addDataPoint(112.82264f);
    dynamicGraph1.addDataPoint(119.35342f);
    dynamicGraph1.addDataPoint(125.91854f);
    dynamicGraph1.addDataPoint(132.46795f);
    dynamicGraph1.addDataPoint(138.95114f);
    dynamicGraph1.addDataPoint(145.31761f);
    dynamicGraph1.addDataPoint(151.51726f);
    dynamicGraph1.addDataPoint(157.50081f);
    dynamicGraph1.addDataPoint(163.22023f);
    dynamicGraph1.addDataPoint(168.62917f);
    dynamicGraph1.addDataPoint(173.6833f);
    dynamicGraph1.addDataPoint(178.34074f);
    dynamicGraph1.addDataPoint(182.56236f);
    dynamicGraph1.addDataPoint(186.31219f);
    dynamicGraph1.addDataPoint(189.55765f);
    dynamicGraph1.addDataPoint(192.26988f);
    dynamicGraph1.addDataPoint(194.42397f);
    dynamicGraph1.addDataPoint(195.99919f);
    dynamicGraph1.addDataPoint(196.97915f);
    dynamicGraph1.addDataPoint(197.35195f);
    dynamicGraph1.addDataPoint(197.11029f);
    dynamicGraph1.addDataPoint(196.25156f);
    dynamicGraph1.addDataPoint(194.77782f);
    dynamicGraph1.addDataPoint(192.69585f);
    dynamicGraph1.addDataPoint(190.01703f);
    dynamicGraph1.addDataPoint(186.75731f);
    dynamicGraph1.addDataPoint(182.93708f);
    dynamicGraph1.addDataPoint(178.58095f);
    dynamicGraph1.addDataPoint(173.7176f);
    dynamicGraph1.addDataPoint(168.37956f);
    dynamicGraph1.addDataPoint(162.60288f);
    dynamicGraph1.addDataPoint(156.4269f);
    dynamicGraph1.addDataPoint(149.89389f);
    dynamicGraph1.addDataPoint(143.0487f);
    dynamicGraph1.addDataPoint(135.93842f);
    dynamicGraph1.addDataPoint(128.61196f);
    dynamicGraph1.addDataPoint(121.11969f);
    dynamicGraph1.addDataPoint(113.51296f);
    dynamicGraph1.addDataPoint(105.84375f);
    dynamicGraph1.addDataPoint(98.16418f);
    dynamicGraph1.addDataPoint(90.52613f);
    dynamicGraph1.addDataPoint(82.98078f);
    dynamicGraph1.addDataPoint(75.57823f);
    dynamicGraph1.addDataPoint(68.36704f);
    dynamicGraph1.addDataPoint(61.39387f);
    dynamicGraph1.addDataPoint(54.70311f);
    dynamicGraph1.addDataPoint(48.33648f);
    dynamicGraph1.addDataPoint(42.33273f);
    dynamicGraph1.addDataPoint(36.7273f);
    dynamicGraph1.addDataPoint(31.55207f);
    dynamicGraph1.addDataPoint(26.83511f);
    dynamicGraph1.addDataPoint(22.6004f);
    dynamicGraph1.addDataPoint(18.86774f);
    dynamicGraph1.addDataPoint(15.65253f);
    dynamicGraph1.addDataPoint(12.96569f);
    dynamicGraph1.addDataPoint(10.81359f);
    dynamicGraph1.addDataPoint(9.19802f);
    dynamicGraph1.addDataPoint(8.11617f);
    dynamicGraph1.addDataPoint(7.56073f);
    dynamicGraph1.addDataPoint(7.51991f);
    dynamicGraph1.addDataPoint(7.97763f);
    dynamicGraph1.addDataPoint(8.91363f);
    dynamicGraph1.addDataPoint(10.30368f);
    dynamicGraph1.addDataPoint(12.11983f);
    dynamicGraph1.addDataPoint(14.33063f);
    dynamicGraph1.addDataPoint(16.90149f);
    dynamicGraph1.addDataPoint(19.7949f);
    dynamicGraph1.addDataPoint(22.97087f);
    dynamicGraph1.addDataPoint(26.38723f);
    dynamicGraph1.addDataPoint(30.00004f);
    dynamicGraph1.addDataPoint(33.76397f);
    dynamicGraph1.addDataPoint(37.63272f);
    dynamicGraph1.addDataPoint(41.55944f);
    dynamicGraph1.addDataPoint(45.49714f);
    dynamicGraph1.addDataPoint(49.39911f);
    dynamicGraph1.addDataPoint(53.21934f);
    dynamicGraph1.addDataPoint(56.91293f);
    dynamicGraph1.addDataPoint(60.43652f);
    dynamicGraph1.addDataPoint(63.74863f);
    dynamicGraph1.addDataPoint(66.81004f);
    dynamicGraph1.addDataPoint(69.58418f);
    dynamicGraph1.addDataPoint(72.03742f);
    dynamicGraph1.addDataPoint(74.1394f);
    dynamicGraph1.addDataPoint(75.86325f);
    dynamicGraph1.addDataPoint(77.18589f);
    dynamicGraph1.addDataPoint(78.08823f);
    dynamicGraph1.addDataPoint(78.55531f);
    dynamicGraph1.addDataPoint(78.57646f);
    dynamicGraph1.addDataPoint(78.14543f);
    dynamicGraph1.addDataPoint(77.26038f);
    dynamicGraph1.addDataPoint(75.92397f);
    dynamicGraph1.addDataPoint(74.14332f);
    dynamicGraph1.addDataPoint(71.92994f);
    dynamicGraph1.addDataPoint(69.29967f);
    dynamicGraph1.addDataPoint(66.27252f);
    dynamicGraph1.addDataPoint(62.87251f);
    dynamicGraph1.addDataPoint(59.12746f);
    dynamicGraph1.addDataPoint(55.06878f);
    dynamicGraph1.addDataPoint(50.73117f);
    dynamicGraph1.addDataPoint(46.15235f);
    dynamicGraph1.addDataPoint(41.37271f);
    dynamicGraph1.addDataPoint(36.43497f);
    dynamicGraph1.addDataPoint(31.38384f);
    dynamicGraph1.addDataPoint(26.26559f);
    dynamicGraph1.addDataPoint(21.12767f);
    dynamicGraph1.addDataPoint(16.01831f);
    dynamicGraph1.addDataPoint(10.98607f);
    dynamicGraph1.addDataPoint(6.07947f);
    dynamicGraph1.addDataPoint(1.3465f);
    dynamicGraph1.addDataPoint(-3.16575f);
    dynamicGraph1.addDataPoint(-7.41153f);
    dynamicGraph1.addDataPoint(-11.3468f);
    dynamicGraph1.addDataPoint(-14.92966f);
    dynamicGraph1.addDataPoint(-18.12067f);
    dynamicGraph1.addDataPoint(-20.88327f);
    dynamicGraph1.addDataPoint(-23.18401f);
    dynamicGraph1.addDataPoint(-24.99295f);
    dynamicGraph1.addDataPoint(-26.28387f);
    dynamicGraph1.addDataPoint(-27.0345f);
    dynamicGraph1.addDataPoint(-27.22679f);
    dynamicGraph1.addDataPoint(-26.84701f);
    dynamicGraph1.addDataPoint(-25.88593f);
    dynamicGraph1.addDataPoint(-24.33888f);
    dynamicGraph1.addDataPoint(-22.20586f);
    dynamicGraph1.addDataPoint(-19.49151f);
    dynamicGraph1.addDataPoint(-16.20509f);
    dynamicGraph1.addDataPoint(-12.36047f);
    dynamicGraph1.addDataPoint(-7.97596f);
    dynamicGraph1.addDataPoint(-3.07423f);
    dynamicGraph1.addDataPoint(2.31788f);
    dynamicGraph1.addDataPoint(8.16958f);
    dynamicGraph1.addDataPoint(14.44638f);
    dynamicGraph1.addDataPoint(21.11034f);
    dynamicGraph1.addDataPoint(28.12036f);
    dynamicGraph1.addDataPoint(35.43258f);
    dynamicGraph1.addDataPoint(43.00066f);
    dynamicGraph1.addDataPoint(50.77617f);
    dynamicGraph1.addDataPoint(58.70902f);
    dynamicGraph1.addDataPoint(66.74783f);
    dynamicGraph1.addDataPoint(74.84036f);
    dynamicGraph1.addDataPoint(82.93392f);
    dynamicGraph1.addDataPoint(90.97584f);

    x_labels.setPosition(21, 176, 147, 15);

    lx0.setXY(120, 0);
    lx0.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lx0.setLinespacing(0);
    lx0.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RAI8));
    x_labels.add(lx0);

    lx10.setXY(80, 0);
    lx10.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lx10.setLinespacing(0);
    lx10.setTypedText(touchgfx::TypedText(T___SINGLEUSE_IRVL));
    x_labels.add(lx10);

    lx20.setXY(40, 0);
    lx20.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lx20.setLinespacing(0);
    lx20.setTypedText(touchgfx::TypedText(T___SINGLEUSE_T3EE));
    x_labels.add(lx20);

    lx30.setXY(0, 0);
    lx30.setColor(touchgfx::Color::getColorFromRGB(255, 255, 255));
    lx30.setLinespacing(0);
    lx30.setTypedText(touchgfx::TypedText(T___SINGLEUSE_RDJE));
    x_labels.add(lx30);

    add(dynamicGraph1);
    add(x_labels);
}

GraphBase::~GraphBase()
{

}

void GraphBase::initialize()
{

}
