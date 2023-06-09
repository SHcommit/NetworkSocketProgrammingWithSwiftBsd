//
//  UIControl+Combine.swift
//  SoTalk
//
//  Created by 양승현 on 2023/05/25.
//

import UIKit
import Combine

@available(iOS 13.0, *)
extension UIControl {
  /// A publihser emitting events.
  func publihser(
    for event: UIControl.Event
  ) -> UIControl.InteractionPublihser {
    return InteractionPublihser(control: self, event: event)
  }
}
