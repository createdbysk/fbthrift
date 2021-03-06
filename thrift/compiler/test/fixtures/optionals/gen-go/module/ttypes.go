// Autogenerated by Thrift Compiler (facebook)
// DO NOT EDIT UNLESS YOU ARE SURE THAT YOU KNOW WHAT YOU ARE DOING
// @generated

package module

import (
	"bytes"
	"context"
	"sync"
	"fmt"
	thrift "github.com/facebook/fbthrift/thrift/lib/go/thrift"
)

// (needed to ensure safety because of naive import list construction.)
var _ = thrift.ZERO
var _ = fmt.Printf
var _ = sync.Mutex{}
var _ = bytes.Equal
var _ = context.Background

var GoUnusedProtection__ int;

type Animal int64
const (
  Animal_DOG Animal = 1
  Animal_CAT Animal = 2
  Animal_TARANTULA Animal = 3
)

var AnimalToName = map[Animal]string {
  Animal_DOG: "DOG",
  Animal_CAT: "CAT",
  Animal_TARANTULA: "TARANTULA",
}

var AnimalToValue = map[string]Animal {
  "DOG": Animal_DOG,
  "CAT": Animal_CAT,
  "TARANTULA": Animal_TARANTULA,
}

var AnimalNames = []string {
  "DOG",
  "CAT",
  "TARANTULA",
}

var AnimalValues = []Animal {
  Animal_DOG,
  Animal_CAT,
  Animal_TARANTULA,
}

func (p Animal) String() string {
  if v, ok := AnimalToName[p]; ok {
    return v
  }
  return "<UNSET>"
}

func AnimalFromString(s string) (Animal, error) {
  if v, ok := AnimalToValue[s]; ok {
    return v, nil
  }
  return Animal(0), fmt.Errorf("not a valid Animal string")
}

func AnimalPtr(v Animal) *Animal { return &v }

type PersonID = int64

func PersonIDPtr(v PersonID) *PersonID { return &v }

// Attributes:
//  - Red
//  - Green
//  - Blue
//  - Alpha
type Color struct {
  Red float64 `thrift:"red,1" db:"red" json:"red"`
  Green float64 `thrift:"green,2" db:"green" json:"green"`
  Blue float64 `thrift:"blue,3" db:"blue" json:"blue"`
  Alpha float64 `thrift:"alpha,4" db:"alpha" json:"alpha"`
}

func NewColor() *Color {
  return &Color{}
}


func (p *Color) GetRed() float64 {
  return p.Red
}

func (p *Color) GetGreen() float64 {
  return p.Green
}

func (p *Color) GetBlue() float64 {
  return p.Blue
}

func (p *Color) GetAlpha() float64 {
  return p.Alpha
}
type ColorBuilder struct {
  obj *Color
}

func NewColorBuilder() *ColorBuilder{
  return &ColorBuilder{
    obj: NewColor(),
  }
}

func (p ColorBuilder) Emit() *Color{
  return &Color{
    Red: p.obj.Red,
    Green: p.obj.Green,
    Blue: p.obj.Blue,
    Alpha: p.obj.Alpha,
  }
}

func (p *ColorBuilder) Red(red float64) *ColorBuilder {
  p.obj.Red = red
  return p
}

func (p *ColorBuilder) Green(green float64) *ColorBuilder {
  p.obj.Green = green
  return p
}

func (p *ColorBuilder) Blue(blue float64) *ColorBuilder {
  p.obj.Blue = blue
  return p
}

func (p *ColorBuilder) Alpha(alpha float64) *ColorBuilder {
  p.obj.Alpha = alpha
  return p
}

func (p *Color) SetRed(red float64) *Color {
  p.Red = red
  return p
}

func (p *Color) SetGreen(green float64) *Color {
  p.Green = green
  return p
}

func (p *Color) SetBlue(blue float64) *Color {
  p.Blue = blue
  return p
}

func (p *Color) SetAlpha(alpha float64) *Color {
  p.Alpha = alpha
  return p
}

func (p *Color) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
    case 3:
      if err := p.ReadField3(iprot); err != nil {
        return err
      }
    case 4:
      if err := p.ReadField4(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *Color)  ReadField1(iprot thrift.Protocol) error {
  if v, err := iprot.ReadDouble(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  p.Red = v
}
  return nil
}

func (p *Color)  ReadField2(iprot thrift.Protocol) error {
  if v, err := iprot.ReadDouble(); err != nil {
  return thrift.PrependError("error reading field 2: ", err)
} else {
  p.Green = v
}
  return nil
}

func (p *Color)  ReadField3(iprot thrift.Protocol) error {
  if v, err := iprot.ReadDouble(); err != nil {
  return thrift.PrependError("error reading field 3: ", err)
} else {
  p.Blue = v
}
  return nil
}

func (p *Color)  ReadField4(iprot thrift.Protocol) error {
  if v, err := iprot.ReadDouble(); err != nil {
  return thrift.PrependError("error reading field 4: ", err)
} else {
  p.Alpha = v
}
  return nil
}

func (p *Color) Write(oprot thrift.Protocol) error {
  if err := oprot.WriteStructBegin("Color"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := p.writeField3(oprot); err != nil { return err }
  if err := p.writeField4(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *Color) writeField1(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("red", thrift.DOUBLE, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:red: ", p), err) }
  if err := oprot.WriteDouble(float64(p.Red)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.red (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:red: ", p), err) }
  return err
}

func (p *Color) writeField2(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("green", thrift.DOUBLE, 2); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:green: ", p), err) }
  if err := oprot.WriteDouble(float64(p.Green)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.green (2) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 2:green: ", p), err) }
  return err
}

func (p *Color) writeField3(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("blue", thrift.DOUBLE, 3); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 3:blue: ", p), err) }
  if err := oprot.WriteDouble(float64(p.Blue)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.blue (3) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 3:blue: ", p), err) }
  return err
}

func (p *Color) writeField4(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("alpha", thrift.DOUBLE, 4); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 4:alpha: ", p), err) }
  if err := oprot.WriteDouble(float64(p.Alpha)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.alpha (4) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 4:alpha: ", p), err) }
  return err
}

func (p *Color) String() string {
  if p == nil {
    return "<nil>"
  }

  redVal := fmt.Sprintf("%v", p.Red)
  greenVal := fmt.Sprintf("%v", p.Green)
  blueVal := fmt.Sprintf("%v", p.Blue)
  alphaVal := fmt.Sprintf("%v", p.Alpha)
  return fmt.Sprintf("Color({Red:%s Green:%s Blue:%s Alpha:%s})", redVal, greenVal, blueVal, alphaVal)
}

// Attributes:
//  - Color
//  - LicensePlate
//  - Description
//  - Name
//  - HasAC
type Vehicle struct {
  Color *Color `thrift:"color,1" db:"color" json:"color"`
  LicensePlate *string `thrift:"licensePlate,2" db:"licensePlate" json:"licensePlate,omitempty"`
  Description *string `thrift:"description,3" db:"description" json:"description,omitempty"`
  Name *string `thrift:"name,4" db:"name" json:"name,omitempty"`
  HasAC bool `thrift:"hasAC,5" db:"hasAC" json:"hasAC,omitempty"`
}

func NewVehicle() *Vehicle {
  return &Vehicle{
    Color: NewColor(),
  }
}

var Vehicle_Color_DEFAULT *Color
func (p *Vehicle) GetColor() *Color {
  if !p.IsSetColor() {
    return Vehicle_Color_DEFAULT
  }
return p.Color
}
var Vehicle_LicensePlate_DEFAULT string
func (p *Vehicle) GetLicensePlate() string {
  if !p.IsSetLicensePlate() {
    return Vehicle_LicensePlate_DEFAULT
  }
return *p.LicensePlate
}
var Vehicle_Description_DEFAULT string
func (p *Vehicle) GetDescription() string {
  if !p.IsSetDescription() {
    return Vehicle_Description_DEFAULT
  }
return *p.Description
}
var Vehicle_Name_DEFAULT string
func (p *Vehicle) GetName() string {
  if !p.IsSetName() {
    return Vehicle_Name_DEFAULT
  }
return *p.Name
}
var Vehicle_HasAC_DEFAULT bool = false

func (p *Vehicle) GetHasAC() bool {
  return p.HasAC
}
func (p *Vehicle) IsSetColor() bool {
  return p != nil && p.Color != nil
}

func (p *Vehicle) IsSetLicensePlate() bool {
  return p != nil && p.LicensePlate != nil
}

func (p *Vehicle) IsSetDescription() bool {
  return p != nil && p.Description != nil
}

func (p *Vehicle) IsSetName() bool {
  return p != nil && p.Name != nil
}

func (p *Vehicle) IsSetHasAC() bool {
  return p != nil && p.HasAC != Vehicle_HasAC_DEFAULT
}

type VehicleBuilder struct {
  obj *Vehicle
}

func NewVehicleBuilder() *VehicleBuilder{
  return &VehicleBuilder{
    obj: NewVehicle(),
  }
}

func (p VehicleBuilder) Emit() *Vehicle{
  return &Vehicle{
    Color: p.obj.Color,
    LicensePlate: p.obj.LicensePlate,
    Description: p.obj.Description,
    Name: p.obj.Name,
    HasAC: p.obj.HasAC,
  }
}

func (p *VehicleBuilder) Color(color *Color) *VehicleBuilder {
  p.obj.Color = color
  return p
}

func (p *VehicleBuilder) LicensePlate(licensePlate *string) *VehicleBuilder {
  p.obj.LicensePlate = licensePlate
  return p
}

func (p *VehicleBuilder) Description(description *string) *VehicleBuilder {
  p.obj.Description = description
  return p
}

func (p *VehicleBuilder) Name(name *string) *VehicleBuilder {
  p.obj.Name = name
  return p
}

func (p *VehicleBuilder) HasAC(hasAC bool) *VehicleBuilder {
  p.obj.HasAC = hasAC
  return p
}

func (p *Vehicle) SetColor(color *Color) *Vehicle {
  p.Color = color
  return p
}

func (p *Vehicle) SetLicensePlate(licensePlate *string) *Vehicle {
  p.LicensePlate = licensePlate
  return p
}

func (p *Vehicle) SetDescription(description *string) *Vehicle {
  p.Description = description
  return p
}

func (p *Vehicle) SetName(name *string) *Vehicle {
  p.Name = name
  return p
}

func (p *Vehicle) SetHasAC(hasAC bool) *Vehicle {
  p.HasAC = hasAC
  return p
}

func (p *Vehicle) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
    case 3:
      if err := p.ReadField3(iprot); err != nil {
        return err
      }
    case 4:
      if err := p.ReadField4(iprot); err != nil {
        return err
      }
    case 5:
      if err := p.ReadField5(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *Vehicle)  ReadField1(iprot thrift.Protocol) error {
  p.Color = NewColor()
  if err := p.Color.Read(iprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error reading struct: ", p.Color), err)
  }
  return nil
}

func (p *Vehicle)  ReadField2(iprot thrift.Protocol) error {
  if v, err := iprot.ReadString(); err != nil {
  return thrift.PrependError("error reading field 2: ", err)
} else {
  p.LicensePlate = &v
}
  return nil
}

func (p *Vehicle)  ReadField3(iprot thrift.Protocol) error {
  if v, err := iprot.ReadString(); err != nil {
  return thrift.PrependError("error reading field 3: ", err)
} else {
  p.Description = &v
}
  return nil
}

func (p *Vehicle)  ReadField4(iprot thrift.Protocol) error {
  if v, err := iprot.ReadString(); err != nil {
  return thrift.PrependError("error reading field 4: ", err)
} else {
  p.Name = &v
}
  return nil
}

func (p *Vehicle)  ReadField5(iprot thrift.Protocol) error {
  if v, err := iprot.ReadBool(); err != nil {
  return thrift.PrependError("error reading field 5: ", err)
} else {
  p.HasAC = v
}
  return nil
}

func (p *Vehicle) Write(oprot thrift.Protocol) error {
  if err := oprot.WriteStructBegin("Vehicle"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := p.writeField3(oprot); err != nil { return err }
  if err := p.writeField4(oprot); err != nil { return err }
  if err := p.writeField5(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *Vehicle) writeField1(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("color", thrift.STRUCT, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:color: ", p), err) }
  if err := p.Color.Write(oprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error writing struct: ", p.Color), err)
  }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:color: ", p), err) }
  return err
}

func (p *Vehicle) writeField2(oprot thrift.Protocol) (err error) {
  if p.IsSetLicensePlate() {
    if err := oprot.WriteFieldBegin("licensePlate", thrift.STRING, 2); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:licensePlate: ", p), err) }
    if err := oprot.WriteString(string(*p.LicensePlate)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.licensePlate (2) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 2:licensePlate: ", p), err) }
  }
  return err
}

func (p *Vehicle) writeField3(oprot thrift.Protocol) (err error) {
  if p.IsSetDescription() {
    if err := oprot.WriteFieldBegin("description", thrift.STRING, 3); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 3:description: ", p), err) }
    if err := oprot.WriteString(string(*p.Description)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.description (3) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 3:description: ", p), err) }
  }
  return err
}

func (p *Vehicle) writeField4(oprot thrift.Protocol) (err error) {
  if p.IsSetName() {
    if err := oprot.WriteFieldBegin("name", thrift.STRING, 4); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 4:name: ", p), err) }
    if err := oprot.WriteString(string(*p.Name)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.name (4) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 4:name: ", p), err) }
  }
  return err
}

func (p *Vehicle) writeField5(oprot thrift.Protocol) (err error) {
  if p.IsSetHasAC() {
    if err := oprot.WriteFieldBegin("hasAC", thrift.BOOL, 5); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 5:hasAC: ", p), err) }
    if err := oprot.WriteBool(bool(p.HasAC)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.hasAC (5) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 5:hasAC: ", p), err) }
  }
  return err
}

func (p *Vehicle) String() string {
  if p == nil {
    return "<nil>"
  }

  var colorVal string
  if p.Color == nil {
    colorVal = "<nil>"
  } else {
    colorVal = fmt.Sprintf("%v", p.Color)
  }
  var licensePlateVal string
  if p.LicensePlate == nil {
    licensePlateVal = "<nil>"
  } else {
    licensePlateVal = fmt.Sprintf("%v", *p.LicensePlate)
  }
  var descriptionVal string
  if p.Description == nil {
    descriptionVal = "<nil>"
  } else {
    descriptionVal = fmt.Sprintf("%v", *p.Description)
  }
  var nameVal string
  if p.Name == nil {
    nameVal = "<nil>"
  } else {
    nameVal = fmt.Sprintf("%v", *p.Name)
  }
  hasACVal := fmt.Sprintf("%v", p.HasAC)
  return fmt.Sprintf("Vehicle({Color:%s LicensePlate:%s Description:%s Name:%s HasAC:%s})", colorVal, licensePlateVal, descriptionVal, nameVal, hasACVal)
}

// Attributes:
//  - Id
//  - Name
//  - Age
//  - Address
//  - FavoriteColor
//  - Friends
//  - BestFriend
//  - PetNames
//  - AfraidOfAnimal
//  - Vehicles
type Person struct {
  Id PersonID `thrift:"id,1" db:"id" json:"id"`
  Name string `thrift:"name,2" db:"name" json:"name"`
  Age *int16 `thrift:"age,3" db:"age" json:"age,omitempty"`
  Address *string `thrift:"address,4" db:"address" json:"address,omitempty"`
  FavoriteColor *Color `thrift:"favoriteColor,5" db:"favoriteColor" json:"favoriteColor,omitempty"`
  Friends []PersonID `thrift:"friends,6" db:"friends" json:"friends,omitempty"`
  BestFriend *PersonID `thrift:"bestFriend,7" db:"bestFriend" json:"bestFriend,omitempty"`
  PetNames map[Animal]string `thrift:"petNames,8" db:"petNames" json:"petNames,omitempty"`
  AfraidOfAnimal *Animal `thrift:"afraidOfAnimal,9" db:"afraidOfAnimal" json:"afraidOfAnimal,omitempty"`
  Vehicles []*Vehicle `thrift:"vehicles,10" db:"vehicles" json:"vehicles,omitempty"`
}

func NewPerson() *Person {
  return &Person{}
}


func (p *Person) GetId() PersonID {
  return p.Id
}

func (p *Person) GetName() string {
  return p.Name
}
var Person_Age_DEFAULT int16
func (p *Person) GetAge() int16 {
  if !p.IsSetAge() {
    return Person_Age_DEFAULT
  }
return *p.Age
}
var Person_Address_DEFAULT string
func (p *Person) GetAddress() string {
  if !p.IsSetAddress() {
    return Person_Address_DEFAULT
  }
return *p.Address
}
var Person_FavoriteColor_DEFAULT *Color
func (p *Person) GetFavoriteColor() *Color {
  if !p.IsSetFavoriteColor() {
    return Person_FavoriteColor_DEFAULT
  }
return p.FavoriteColor
}
var Person_Friends_DEFAULT []PersonID

func (p *Person) GetFriends() []PersonID {
  return p.Friends
}
var Person_BestFriend_DEFAULT PersonID
func (p *Person) GetBestFriend() PersonID {
  if !p.IsSetBestFriend() {
    return Person_BestFriend_DEFAULT
  }
return *p.BestFriend
}
var Person_PetNames_DEFAULT map[Animal]string

func (p *Person) GetPetNames() map[Animal]string {
  return p.PetNames
}
var Person_AfraidOfAnimal_DEFAULT Animal
func (p *Person) GetAfraidOfAnimal() Animal {
  if !p.IsSetAfraidOfAnimal() {
    return Person_AfraidOfAnimal_DEFAULT
  }
return *p.AfraidOfAnimal
}
var Person_Vehicles_DEFAULT []*Vehicle

func (p *Person) GetVehicles() []*Vehicle {
  return p.Vehicles
}
func (p *Person) IsSetAge() bool {
  return p != nil && p.Age != nil
}

func (p *Person) IsSetAddress() bool {
  return p != nil && p.Address != nil
}

func (p *Person) IsSetFavoriteColor() bool {
  return p != nil && p.FavoriteColor != nil
}

func (p *Person) IsSetFriends() bool {
  return p != nil && p.Friends != nil
}

func (p *Person) IsSetBestFriend() bool {
  return p != nil && p.BestFriend != nil
}

func (p *Person) IsSetPetNames() bool {
  return p != nil && p.PetNames != nil
}

func (p *Person) IsSetAfraidOfAnimal() bool {
  return p != nil && p.AfraidOfAnimal != nil
}

func (p *Person) IsSetVehicles() bool {
  return p != nil && p.Vehicles != nil
}

type PersonBuilder struct {
  obj *Person
}

func NewPersonBuilder() *PersonBuilder{
  return &PersonBuilder{
    obj: NewPerson(),
  }
}

func (p PersonBuilder) Emit() *Person{
  return &Person{
    Id: p.obj.Id,
    Name: p.obj.Name,
    Age: p.obj.Age,
    Address: p.obj.Address,
    FavoriteColor: p.obj.FavoriteColor,
    Friends: p.obj.Friends,
    BestFriend: p.obj.BestFriend,
    PetNames: p.obj.PetNames,
    AfraidOfAnimal: p.obj.AfraidOfAnimal,
    Vehicles: p.obj.Vehicles,
  }
}

func (p *PersonBuilder) Id(id PersonID) *PersonBuilder {
  p.obj.Id = id
  return p
}

func (p *PersonBuilder) Name(name string) *PersonBuilder {
  p.obj.Name = name
  return p
}

func (p *PersonBuilder) Age(age *int16) *PersonBuilder {
  p.obj.Age = age
  return p
}

func (p *PersonBuilder) Address(address *string) *PersonBuilder {
  p.obj.Address = address
  return p
}

func (p *PersonBuilder) FavoriteColor(favoriteColor *Color) *PersonBuilder {
  p.obj.FavoriteColor = favoriteColor
  return p
}

func (p *PersonBuilder) Friends(friends []PersonID) *PersonBuilder {
  p.obj.Friends = friends
  return p
}

func (p *PersonBuilder) BestFriend(bestFriend *PersonID) *PersonBuilder {
  p.obj.BestFriend = bestFriend
  return p
}

func (p *PersonBuilder) PetNames(petNames map[Animal]string) *PersonBuilder {
  p.obj.PetNames = petNames
  return p
}

func (p *PersonBuilder) AfraidOfAnimal(afraidOfAnimal *Animal) *PersonBuilder {
  p.obj.AfraidOfAnimal = afraidOfAnimal
  return p
}

func (p *PersonBuilder) Vehicles(vehicles []*Vehicle) *PersonBuilder {
  p.obj.Vehicles = vehicles
  return p
}

func (p *Person) SetId(id PersonID) *Person {
  p.Id = id
  return p
}

func (p *Person) SetName(name string) *Person {
  p.Name = name
  return p
}

func (p *Person) SetAge(age *int16) *Person {
  p.Age = age
  return p
}

func (p *Person) SetAddress(address *string) *Person {
  p.Address = address
  return p
}

func (p *Person) SetFavoriteColor(favoriteColor *Color) *Person {
  p.FavoriteColor = favoriteColor
  return p
}

func (p *Person) SetFriends(friends []PersonID) *Person {
  p.Friends = friends
  return p
}

func (p *Person) SetBestFriend(bestFriend *PersonID) *Person {
  p.BestFriend = bestFriend
  return p
}

func (p *Person) SetPetNames(petNames map[Animal]string) *Person {
  p.PetNames = petNames
  return p
}

func (p *Person) SetAfraidOfAnimal(afraidOfAnimal *Animal) *Person {
  p.AfraidOfAnimal = afraidOfAnimal
  return p
}

func (p *Person) SetVehicles(vehicles []*Vehicle) *Person {
  p.Vehicles = vehicles
  return p
}

func (p *Person) Read(iprot thrift.Protocol) error {
  if _, err := iprot.ReadStructBegin(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read error: ", p), err)
  }


  for {
    _, fieldTypeId, fieldId, err := iprot.ReadFieldBegin()
    if err != nil {
      return thrift.PrependError(fmt.Sprintf("%T field %d read error: ", p, fieldId), err)
    }
    if fieldTypeId == thrift.STOP { break; }
    switch fieldId {
    case 1:
      if err := p.ReadField1(iprot); err != nil {
        return err
      }
    case 2:
      if err := p.ReadField2(iprot); err != nil {
        return err
      }
    case 3:
      if err := p.ReadField3(iprot); err != nil {
        return err
      }
    case 4:
      if err := p.ReadField4(iprot); err != nil {
        return err
      }
    case 5:
      if err := p.ReadField5(iprot); err != nil {
        return err
      }
    case 6:
      if err := p.ReadField6(iprot); err != nil {
        return err
      }
    case 7:
      if err := p.ReadField7(iprot); err != nil {
        return err
      }
    case 8:
      if err := p.ReadField8(iprot); err != nil {
        return err
      }
    case 9:
      if err := p.ReadField9(iprot); err != nil {
        return err
      }
    case 10:
      if err := p.ReadField10(iprot); err != nil {
        return err
      }
    default:
      if err := iprot.Skip(fieldTypeId); err != nil {
        return err
      }
    }
    if err := iprot.ReadFieldEnd(); err != nil {
      return err
    }
  }
  if err := iprot.ReadStructEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T read struct end error: ", p), err)
  }
  return nil
}

func (p *Person)  ReadField1(iprot thrift.Protocol) error {
  if v, err := iprot.ReadI64(); err != nil {
  return thrift.PrependError("error reading field 1: ", err)
} else {
  temp := PersonID(v)
  p.Id = temp
}
  return nil
}

func (p *Person)  ReadField2(iprot thrift.Protocol) error {
  if v, err := iprot.ReadString(); err != nil {
  return thrift.PrependError("error reading field 2: ", err)
} else {
  p.Name = v
}
  return nil
}

func (p *Person)  ReadField3(iprot thrift.Protocol) error {
  if v, err := iprot.ReadI16(); err != nil {
  return thrift.PrependError("error reading field 3: ", err)
} else {
  p.Age = &v
}
  return nil
}

func (p *Person)  ReadField4(iprot thrift.Protocol) error {
  if v, err := iprot.ReadString(); err != nil {
  return thrift.PrependError("error reading field 4: ", err)
} else {
  p.Address = &v
}
  return nil
}

func (p *Person)  ReadField5(iprot thrift.Protocol) error {
  p.FavoriteColor = NewColor()
  if err := p.FavoriteColor.Read(iprot); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T error reading struct: ", p.FavoriteColor), err)
  }
  return nil
}

func (p *Person)  ReadField6(iprot thrift.Protocol) error {
  _, size, err := iprot.ReadSetBegin()
  if err != nil {
    return thrift.PrependError("error reading set begin: ", err)
  }
  tSet := make([]PersonID, 0, size)
  p.Friends =  tSet
  for i := 0; i < size; i ++ {
var _elem0 PersonID
    if v, err := iprot.ReadI64(); err != nil {
    return thrift.PrependError("error reading field 0: ", err)
} else {
    temp := PersonID(v)
    _elem0 = temp
}
    p.Friends = append(p.Friends, _elem0)
  }
  if err := iprot.ReadSetEnd(); err != nil {
    return thrift.PrependError("error reading set end: ", err)
  }
  return nil
}

func (p *Person)  ReadField7(iprot thrift.Protocol) error {
  if v, err := iprot.ReadI64(); err != nil {
  return thrift.PrependError("error reading field 7: ", err)
} else {
  temp := PersonID(v)
  p.BestFriend = &temp
}
  return nil
}

func (p *Person)  ReadField8(iprot thrift.Protocol) error {
  _, _, size, err := iprot.ReadMapBegin()
  if err != nil {
    return thrift.PrependError("error reading map begin: ", err)
  }
  tMap := make(map[Animal]string, size)
  p.PetNames =  tMap
  for i := 0; i < size; i ++ {
var _key1 Animal
    if v, err := iprot.ReadI32(); err != nil {
    return thrift.PrependError("error reading field 0: ", err)
} else {
    temp := Animal(v)
    _key1 = temp
}
var _val2 string
    if v, err := iprot.ReadString(); err != nil {
    return thrift.PrependError("error reading field 0: ", err)
} else {
    _val2 = v
}
    p.PetNames[_key1] = _val2
  }
  if err := iprot.ReadMapEnd(); err != nil {
    return thrift.PrependError("error reading map end: ", err)
  }
  return nil
}

func (p *Person)  ReadField9(iprot thrift.Protocol) error {
  if v, err := iprot.ReadI32(); err != nil {
  return thrift.PrependError("error reading field 9: ", err)
} else {
  temp := Animal(v)
  p.AfraidOfAnimal = &temp
}
  return nil
}

func (p *Person)  ReadField10(iprot thrift.Protocol) error {
  _, size, err := iprot.ReadListBegin()
  if err != nil {
    return thrift.PrependError("error reading list begin: ", err)
  }
  tSlice := make([]*Vehicle, 0, size)
  p.Vehicles =  tSlice
  for i := 0; i < size; i ++ {
    _elem3 := NewVehicle()
    if err := _elem3.Read(iprot); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T error reading struct: ", _elem3), err)
    }
    p.Vehicles = append(p.Vehicles, _elem3)
  }
  if err := iprot.ReadListEnd(); err != nil {
    return thrift.PrependError("error reading list end: ", err)
  }
  return nil
}

func (p *Person) Write(oprot thrift.Protocol) error {
  if err := oprot.WriteStructBegin("Person"); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write struct begin error: ", p), err) }
  if err := p.writeField1(oprot); err != nil { return err }
  if err := p.writeField2(oprot); err != nil { return err }
  if err := p.writeField3(oprot); err != nil { return err }
  if err := p.writeField4(oprot); err != nil { return err }
  if err := p.writeField5(oprot); err != nil { return err }
  if err := p.writeField6(oprot); err != nil { return err }
  if err := p.writeField7(oprot); err != nil { return err }
  if err := p.writeField8(oprot); err != nil { return err }
  if err := p.writeField9(oprot); err != nil { return err }
  if err := p.writeField10(oprot); err != nil { return err }
  if err := oprot.WriteFieldStop(); err != nil {
    return thrift.PrependError("write field stop error: ", err) }
  if err := oprot.WriteStructEnd(); err != nil {
    return thrift.PrependError("write struct stop error: ", err) }
  return nil
}

func (p *Person) writeField1(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("id", thrift.I64, 1); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 1:id: ", p), err) }
  if err := oprot.WriteI64(int64(p.Id)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.id (1) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 1:id: ", p), err) }
  return err
}

func (p *Person) writeField2(oprot thrift.Protocol) (err error) {
  if err := oprot.WriteFieldBegin("name", thrift.STRING, 2); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field begin error 2:name: ", p), err) }
  if err := oprot.WriteString(string(p.Name)); err != nil {
  return thrift.PrependError(fmt.Sprintf("%T.name (2) field write error: ", p), err) }
  if err := oprot.WriteFieldEnd(); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T write field end error 2:name: ", p), err) }
  return err
}

func (p *Person) writeField3(oprot thrift.Protocol) (err error) {
  if p.IsSetAge() {
    if err := oprot.WriteFieldBegin("age", thrift.I16, 3); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 3:age: ", p), err) }
    if err := oprot.WriteI16(int16(*p.Age)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.age (3) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 3:age: ", p), err) }
  }
  return err
}

func (p *Person) writeField4(oprot thrift.Protocol) (err error) {
  if p.IsSetAddress() {
    if err := oprot.WriteFieldBegin("address", thrift.STRING, 4); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 4:address: ", p), err) }
    if err := oprot.WriteString(string(*p.Address)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.address (4) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 4:address: ", p), err) }
  }
  return err
}

func (p *Person) writeField5(oprot thrift.Protocol) (err error) {
  if p.IsSetFavoriteColor() {
    if err := oprot.WriteFieldBegin("favoriteColor", thrift.STRUCT, 5); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 5:favoriteColor: ", p), err) }
    if err := p.FavoriteColor.Write(oprot); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T error writing struct: ", p.FavoriteColor), err)
    }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 5:favoriteColor: ", p), err) }
  }
  return err
}

func (p *Person) writeField6(oprot thrift.Protocol) (err error) {
  if p.IsSetFriends() {
    if err := oprot.WriteFieldBegin("friends", thrift.SET, 6); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 6:friends: ", p), err) }
    if err := oprot.WriteSetBegin(thrift.I64, len(p.Friends)); err != nil {
      return thrift.PrependError("error writing set begin: ", err)
    }
    set := make(map[PersonID]bool, len(p.Friends))
    for _, v := range p.Friends {
      if ok := set[v]; ok {
        return thrift.PrependError("", fmt.Errorf("%T error writing set field: slice is not unique", v))
      }
      set[v] = true
    }
    for _, v := range p.Friends {
      if err := oprot.WriteI64(int64(v)); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T. (0) field write error: ", p), err) }
    }
    if err := oprot.WriteSetEnd(); err != nil {
      return thrift.PrependError("error writing set end: ", err)
    }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 6:friends: ", p), err) }
  }
  return err
}

func (p *Person) writeField7(oprot thrift.Protocol) (err error) {
  if p.IsSetBestFriend() {
    if err := oprot.WriteFieldBegin("bestFriend", thrift.I64, 7); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 7:bestFriend: ", p), err) }
    if err := oprot.WriteI64(int64(*p.BestFriend)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.bestFriend (7) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 7:bestFriend: ", p), err) }
  }
  return err
}

func (p *Person) writeField8(oprot thrift.Protocol) (err error) {
  if p.IsSetPetNames() {
    if err := oprot.WriteFieldBegin("petNames", thrift.MAP, 8); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 8:petNames: ", p), err) }
    if err := oprot.WriteMapBegin(thrift.I32, thrift.STRING, len(p.PetNames)); err != nil {
      return thrift.PrependError("error writing map begin: ", err)
    }
    for k, v := range p.PetNames {
      if err := oprot.WriteI32(int32(k)); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T. (0) field write error: ", p), err) }
      if err := oprot.WriteString(string(v)); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T. (0) field write error: ", p), err) }
    }
    if err := oprot.WriteMapEnd(); err != nil {
      return thrift.PrependError("error writing map end: ", err)
    }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 8:petNames: ", p), err) }
  }
  return err
}

func (p *Person) writeField9(oprot thrift.Protocol) (err error) {
  if p.IsSetAfraidOfAnimal() {
    if err := oprot.WriteFieldBegin("afraidOfAnimal", thrift.I32, 9); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 9:afraidOfAnimal: ", p), err) }
    if err := oprot.WriteI32(int32(*p.AfraidOfAnimal)); err != nil {
    return thrift.PrependError(fmt.Sprintf("%T.afraidOfAnimal (9) field write error: ", p), err) }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 9:afraidOfAnimal: ", p), err) }
  }
  return err
}

func (p *Person) writeField10(oprot thrift.Protocol) (err error) {
  if p.IsSetVehicles() {
    if err := oprot.WriteFieldBegin("vehicles", thrift.LIST, 10); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field begin error 10:vehicles: ", p), err) }
    if err := oprot.WriteListBegin(thrift.STRUCT, len(p.Vehicles)); err != nil {
      return thrift.PrependError("error writing list begin: ", err)
    }
    for _, v := range p.Vehicles {
      if err := v.Write(oprot); err != nil {
        return thrift.PrependError(fmt.Sprintf("%T error writing struct: ", v), err)
      }
    }
    if err := oprot.WriteListEnd(); err != nil {
      return thrift.PrependError("error writing list end: ", err)
    }
    if err := oprot.WriteFieldEnd(); err != nil {
      return thrift.PrependError(fmt.Sprintf("%T write field end error 10:vehicles: ", p), err) }
  }
  return err
}

func (p *Person) String() string {
  if p == nil {
    return "<nil>"
  }

  idVal := fmt.Sprintf("%v", p.Id)
  nameVal := fmt.Sprintf("%v", p.Name)
  var ageVal string
  if p.Age == nil {
    ageVal = "<nil>"
  } else {
    ageVal = fmt.Sprintf("%v", *p.Age)
  }
  var addressVal string
  if p.Address == nil {
    addressVal = "<nil>"
  } else {
    addressVal = fmt.Sprintf("%v", *p.Address)
  }
  var favoriteColorVal string
  if p.FavoriteColor == nil {
    favoriteColorVal = "<nil>"
  } else {
    favoriteColorVal = fmt.Sprintf("%v", p.FavoriteColor)
  }
  friendsVal := fmt.Sprintf("%v", p.Friends)
  var bestFriendVal string
  if p.BestFriend == nil {
    bestFriendVal = "<nil>"
  } else {
    bestFriendVal = fmt.Sprintf("%v", *p.BestFriend)
  }
  petNamesVal := fmt.Sprintf("%v", p.PetNames)
  var afraidOfAnimalVal string
  if p.AfraidOfAnimal == nil {
    afraidOfAnimalVal = "<nil>"
  } else {
    afraidOfAnimalVal = fmt.Sprintf("%v", *p.AfraidOfAnimal)
  }
  vehiclesVal := fmt.Sprintf("%v", p.Vehicles)
  return fmt.Sprintf("Person({Id:%s Name:%s Age:%s Address:%s FavoriteColor:%s Friends:%s BestFriend:%s PetNames:%s AfraidOfAnimal:%s Vehicles:%s})", idVal, nameVal, ageVal, addressVal, favoriteColorVal, friendsVal, bestFriendVal, petNamesVal, afraidOfAnimalVal, vehiclesVal)
}

